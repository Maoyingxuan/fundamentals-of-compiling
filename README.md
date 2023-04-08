# - 本仓库为四川大学2020级计算机学院本科 编译原理课程实验
## C-Minus 的词法规则
- 关键字： if  else  int  return  void  while
- 专用符号：  +  -  *  /  <  <=  >  >=  ==  !=  =  ;  ,  (  )  [  ]  {  }  /*  */
- 其他标记为 ID 和 NUM 
```
ID = letter letter*
NUM = digit digit*
Letter = a|..|z|A|..|Z
Digit = 0|..|9
```
- 空格由空白、换行符、制表符组成。
- 注释由 /\*...\*/ 围起来。