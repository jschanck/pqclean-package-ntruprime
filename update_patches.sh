V1=supercop-20200826
V2=supercop-20200826-patched

PYTHON=/usr/bin/python3

WORKDIR=`dirname $0`
WORKDIR=`cd ${WORKDIR} && pwd`
PATCHES=${WORKDIR}/patches
SCRIPTS=${WORKDIR}/scripts

cd ${WORKDIR}

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
  done
)
mv ${PATCHES}/tmp/* ${PATCHES}
rm -rf ${PATCHES}/tmp/
