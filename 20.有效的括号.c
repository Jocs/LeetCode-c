/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (38.78%)
 * Likes:    935
 * Dislikes: 0
 * Total Accepted:    97.5K
 * Total Submissions: 250.6K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
#include <stdio.h>
#include <string.h>

#define LIMIT 10000

char stack[LIMIT];
int pointer = 0;

void push(char s) {
  if (pointer > LIMIT) {
    printf("Over stack");
  }

  stack[pointer++] = s;
}

char pop() {
  if (pointer == -1) {
    printf("The stack is empty!");
  }

  return stack[--pointer];
}

char peek() {
  return stack[pointer - 1];
}


bool isValid(char * s){
  pointer = 0;
  int len = strlen(s);
  int i;
  if (len == 0) {
    return true;
  }

  for (i = 0; i < len; ++i) {
    char c = s[i];
    if (c != '{' && c != '}' && c != '(' && c != ')' && c != '[' && c != ']') {
      continue;
    }
    if (i == 0) {
      push(c);
    } else {
      if (c == '(' || c == '{' || c == '[') {
        push(c);
      } else {
        if (pointer == 0) {
          return false;
        }
        char pk = peek();
        if (pk == '(' && c == ')' || pk == '[' && c == ']' || pk == '{' && c == '}') {
          pop();
        } else {
          push(c);
        }
      }
    }
  }

  return pointer == 0;
}



