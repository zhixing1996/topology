#!/bin/bash

# The following statements set the package path automatically.
mkdir -p bin
pkgPath=`pwd`
verNum=$(git describe --tags `git rev-list --tags --max-count=1`)
sed -i 's:m_pkgPath=.*:m_pkgPath=\"'$pkgPath'\/\";:g' include/topoana.h 
sed -i 's:RequirePackage.*ifxetex:RequirePackage{'$pkgPath'/share/ifxetex:g' share/geometry.sty
sed -i 's:m_verNum=.*:m_verNum=\"'$verNum'\";:g' include/topoana.h

# The following statements recompile the package.
cxxfile="src/*.cpp"
exefile="bin/topoana.exe"
if [ -f $exefile ]
then
rm $exefile
fi
ROOTCFLAGS=`root-config --cflags`
ROOTLDFLAGS=`root-config --ldflags --glibs`
verNum=`gcc --version|sed -n '1p'|awk '{print $3}'|awk -F \. '{print $1$2}'`
if [ $verNum -gt 46 ]
then
g++ -g -Wall ${ROOTCFLAGS} ${ROOTLDFLAGS} -lTreePlayer -o ${exefile} ${cxxfile}
else
g++ -g -Wall -std=c++0x ${ROOTCFLAGS} ${ROOTLDFLAGS} -lTreePlayer -o ${exefile} ${cxxfile}
fi
bash
