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
  echo "${V1} not found"
  exit
fi

if [ ! -e "${V2}" ]
then
  echo "${V2} not found"
  exit
fi

rm -rf ${PATCHES}
mkdir -p ${PATCHES}/tmp/

diff -ru --no-dereference ${V1} ${V2} > ${PATCHES}/tmp/p

( cd ${PATCHES}/tmp/
  splitpatch ${PATCHES}/tmp/p
  rm ${PATCHES}/tmp/p
  for X in *
  do
    Y=$(echo ${X} \
        | head -n 1 ${X} \
        | tr '\t' ' ' \
        | cut -d ' ' -f 2 \
        | cut -d'/' -f 2- \
        | tr '/' '_')
  mv ${X} ${Y}
  sed -i '1,2 s/\t.*$//' ${Y}
  done
)
mv ${PATCHES}/tmp/* ${PATCHES}
rm -rf ${PATCHES}/tmp/
