#!/bin/bash


if [ $# -ne 1 ]; then
    echo "Usage: R00TLeLogon AUserName"
    exit;
fi

#look to see if there is a R00TLeInstall
flag=$(env | grep "R00TLeInstall")

if [ "$flag" == "" ]; then #failed

    echo "Did not find R00TLeInstall enviroment variable"
    echo "Run the Make Install for R00TLe"
    echo "Then source your .bashrc"
    exit;

fi

echo "Setting enviorment"
export ANAROOT_PRM=/user/e10003/R00TLe/prm

cd $R00TLeInstall

##make directory for user
if [ ! -d users/$1 ]; then
    echo "Making a directory for $1 in ${R00TLeInstall}/users"
    mkdir -p users/$1
else 
    echo "User $1 found. Won't make start up files"
    exit;
fi
cd users/$1 # change directory in to the users directory

### Make a rootrc
rm -f .rootrc
echo "Rint.HistSize 500" >> .rootrc
echo "Rint.HistSave 100" >> .rootrc

echo "Unix.*.Root.DynamicPath: .:${R00TLeInstall}/lib:\$(ROOTSYS)/lib" >> .rootrc
echo "Unix.*.Root.MacroPath: .:${R00TLeInstall}/lib:\$(ROOTSYS)/lib" >> .rootrc
echo "Rint.Logon: ${R00TLeInstall}/users/$1/rootlogon.C">>.rootrc

###Make a rootlogon
rm -f rootlogon.C

echo "rootlogon(){">>rootlogon.C
echo "cout<<\"\\nWelcome to R00TLe\\n\"<<endl;" >>rootlogon.C
echo "gSystem->Load(\"libLendaEvent.so\");">>rootlogon.C
echo "gSystem->Load(\"libS800.so\");">>rootlogon.C
echo "gSystem->Load(\"libDDASEvent.so\");">>rootlogon.C
echo "gSystem->Load(\"libLendaSettings.so\");">>rootlogon.C
echo "return;">>rootlogon.C
echo "}">>rootlogon.C









