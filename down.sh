#!/bin/bash
downloadUrl=$1
filename=$2

if [ -z $filename ];then
    echo "filename is null"
    exit
fi

if [ ! -f $filename ];then
    wget $downloadUrl
    echo "下载完成"
fi

if [ ! -f $filename ];then
    echo "下载失败"
    exit
fi

if [ ! -d "./tarDir" ];then
    mkdir tarDir
fi

unzip -o $filename -d ./tarDir
