# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.
import json
import os
import shutil
import sys
from urllib import request

from pip._vendor import requests

des_root_path = ""
fileList = []
version = ""

def main(path):
    for root, dirs, files in os.walk(path):
        for dirName in dirs:
            if dirName.lower() == 'headers':
                (_, extension) = os.path.splitext(root)
                if extension.lower() == ".framework":
                    normalpath = os.path.join(root, dirName)
                    copyFile(normalpath)

def copyFile(path):
    for root, dirs, files in os.walk(path):

        # for dir in dirs:
        #     copyFile(dir)

        file_splits = root.split("/")
        fDir = file_splits.pop()
        gDir = file_splits.pop()

        # print(fDir + ".." + gDir)
        desi_path = os.path.join(des_root_path, os.path.join(gDir, version, fDir))

        # 如果为空 直接返回
        if len(files) == 0:
            return

        fileList.append(root)
        mkdir_recursively(desi_path)

        for file in files:
            src_path = os.path.join(root, file)
            shutil.copy(src_path, desi_path)

def mkdir_recursively(path):

    path_list = path.split('/')
    if path_list is None:
        return False

    disk_name = path_list[0]
    dir = ''
    if path_list[0] == '':
        dir = "/"

    for path_item in path_list:
        dir = os.path.join(dir, path_item)
        if not os.path.exists(dir):
            os.mkdir(dir)

    # 清空操作
    for file in os.listdir(dir):
        os.remove(os.path.join(dir, file))
    return True

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    moudleName = sys.argv[1]
    version = sys.argv[2]

    os.system("pod spec cat " + moudleName + " > a.json")

    # print(des_root_path)
    # main(scanFath)
    f = open("a.json")
    str = f.read()
    json_str = json.loads(str)
    zipStr = json_str["source"]["http"]
    iosPath = ""
    if 'vendored_frameworks' in json_str:
        iosPath = json_str["vendored_frameworks"]
    if iosPath == "" and "ios" in json_str:
        if "vendored_frameworks" in json_str["ios"] :
            iosPath = json_str["ios"]["vendored_frameworks"]
    if iosPath == "":
        print("该SDK 提取文件出错")
        exit()
    (_, filename) = os.path.split(zipStr)
    (_, fileType) = os.path.splitext(filename)

    #真实文件名
    realname = moudleName + "-" + version + fileType
    if filename != realname:
        (p,_) = os.path.split(zipStr)
        zipStr = os.path.join(p, realname)
        filename = realname

    (cdPath, pattenname) = os.path.split(iosPath)
    os.system("sh down.sh " + zipStr + " " + filename)

    scanFath = "./tarDir/" + cdPath
    des_root_path = "./header/"
    main(scanFath)

    os.system("rm -rf ./tarDir a.json " + filename)
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
