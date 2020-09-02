PYTHON=/usr/bin/python3

WORKDIR=`dirname $0`
WORKDIR=`cd ${WORKDIR} && pwd`
PATCHES=${WORKDIR}/patches
SCRIPTS=${WORKDIR}/scripts

cd ${WORKDIR}

V1=$(cat VERSION)
V2=${V1}-patched

if [ ! -e "${V1}" ]
then
  if [ ! -f ${V1}.tar.xz ]
  then
    wget https://bench.cr.yp.to/supercop/${V1}.tar.xz
  fi
  unxz < ${V1}.tar.xz | tar -xf -
fi

if [ -e "${V2}" ]
then
  read -p "${V2} directory already exists. Delete it? " yn
  if [ "${yn:-n}" != "y" ]
  then
    exit -1
  fi
  rm -rf ${V2}
fi

cp -rp ${V1} ${V2}
( cd ${V2}
for X in ${PATCHES}/*
do
  patch -p1 < ${X}
done
)
