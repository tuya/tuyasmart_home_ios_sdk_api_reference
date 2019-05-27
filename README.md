# API Reference



##### 工具安装

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

  ```
  appledoc --project-name 你的工程名字 --project-company 公司名 ./(导出路径，这里是指根目录)  path所要导出的文档的类文件夹
  ```

##### 支持的注释

- 文档中的注释只有符合规范，才能被appledoc认可。

  凡是以 "///"、"/**"或"/*!"开头的注释块，都算所appledoc注释

```
/// 这是单行注释。
 
/** 这也是单行注释 */
 
/*! 同样是单行注释 */
 
/** 这也是单行注释，
*  第二行会接上第一行。
*/
```

