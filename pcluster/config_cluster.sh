#!/bin/bash

ip=$1

scp -i ~/.ssh/calico.pem ~/.ssh/id_github ${ip}/.ssh/

ssh -i ~/.ssh/calico.pem ${ip} mkdir /scratch/build

scp -i ~/.ssh/calico.pem patch.mpif-sizeof.h ${ip}:/scratch/build
scp -i ~/.ssh/calico.pem postinstall.sh ${ip}:/scratch/build
scp -i ~/.ssh/calico.pem patch.mpif-sizeof.h ${ip}:/scratch/build

ssh -i ~/.ssh/calico.pem patch mpif-sizeof.h.orig.test  > patch.mpif-sizeof.h 
