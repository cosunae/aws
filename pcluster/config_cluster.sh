#!/bin/bash

ip=$1

scp -i ~/.ssh/id_aws.pub ~/.ssh/id_github ${ip}:~/.ssh/

ssh -i ~/.ssh/id_aws.pub ${ip} mkdir /scratch/build

scp -i ~/.ssh/id_aws.pub patch.mpif-sizeof.h ${ip}:/scratch/build
scp -i ~/.ssh/id_aws.pub postinstall.sh ${ip}:/scratch/build
scp -i ~/.ssh/id_aws.pub patch.mpif-sizeof.h ${ip}:/scratch/build

ssh -i ~/.ssh/id_aws.pub ${ip} sudo patch /opt/amazon/openmpi/include/mpif-sizeof.h /scratch/build/patch.mpif-sizeof.h 
