# API Reference

 

#####  工具安装

- 安装appledoc

  ```
  git clone git://github.com/tomaz/appledoc.git
  cd ./appledoc
  sudo sh install-appledoc.sh
  ```

- 验证

  ```
  appledoc --version
  appledoc --help
  ```

##### 使用方法

- 进入项目 cd 目录

- 导入目录

  - appledoc --project-name API Reference --project-company tuya.Inc ./

  ```
  appledoc --project-name 你的工程名字 --project-company 公司名 ./(导出路径，这里是指根目录)  path所要导出的文档的类文件夹
  ```

##### 支持的注释

- 头文件的注释只有符合规范，才能被 appledoc 认可

```
/// 这是单行注释。
 
/** 这也是单行注释 */
 
/*! 同样是单行注释 */
 
/** 这也是单行注释，
*  第二行会接上第一行。
*/
```

##### 比较好的注释

```
/**
 @brief     -->简要描述
 @param     -->用于参数说明
 @see       -->可见的链接性说明，文档中可对应链接到内容 一般可用于注释枚举属性的类型
 @discussion        -->详细说明 提醒信息
 @warning       -->警告内容
 @bug       -->bug内容
 @return        -->返回值说明
 */
```

脚本

```
#!/bin/bash
appledoc \                                                                                             
#工程的名字
--project-name "testAppledocDemo" \
#公司的名字
--project-company "Zyp" \
#不生成docset，直接输出html
--no-create-docset \
#没有注释的文件也输出html  -->目的是看到所有的文件
--keep-undocumented-objects \
#没有注释的属性和方法也输出到html  -->目的是看到所有的属性和方法
--keep-undocumented-members \
#没有注释的文件不提示警告
--no-warn-undocumented-object \
#没有注释的属性和方法不提示警告
--no-warn-undocumented-member \
#需要输出的文件路径  -->这里推荐最好直接为当前工程路径平级输出，便于维护和使用
./
```

