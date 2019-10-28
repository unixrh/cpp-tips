1. absl::string_view  具有const特点，并省去string 和char* 的转换
> ```c++
> void TakesCharStar(const char* s);             // C convention
> void TakesString(const string& s);             // Old Standard C++ convention
> void TakesStringView(absl::string_view s);     // Abseil C++ convention
> void TakesStringView(std::string_view s);      // C++17 C++ convention
>```
2. 字符串连接：absl::StrCat / absl::StrAppend VS '+'
    - '+' 号连接三个以上字符串时，会产生临时string变量；
    - StrCat和strAppend会先计算需要的长度，更加高效；
3. 分隔字符串: absl::StrSplit
    - 大多数实现方案限定返回类型，不够通用
    - absl::StrSplit，实现按多种方式分隔，并且支持返回多种类型
>```c++
>// Splits on commas. Stores in vector of string_view (no copies).
>std::vector<absl::string_view> v = absl::StrSplit("a,b,c", ',');
>
>// Splits on commas. Stores in vector of string (data copied once).
>std::vector<std::string> v = absl::StrSplit("a,b,c", ',');
>
>// Splits on literal string "=>" (not either of "=" or ">")
>std::vector<absl::string_view> v = absl::StrSplit("a=>b=>c", "=>");
>
>// Splits on any of the given characters (',' or ';')
>using absl::ByAnyChar;
>std::vector<std::string> v = absl::StrSplit("a,b;c", ByAnyChar(",;"));
>
>// Stores in various containers (also works w/ absl::string_view)
>std::set<std::string> s = absl::StrSplit("a,b,c", ',');
>std::multiset<std::string> s = absl::StrSplit("a,b,c", ',');
>std::list<std::string> li = absl::StrSplit("a,b,c", ',');
>
>// Equiv. to the mythical SplitStringViewToDequeOfStringAllowEmpty()
>std::deque<std::string> d = absl::StrSplit("a,b,c", ',');
>
>// Yields "a"->"1", "b"->"2", "c"->"3"
>std::map<std::string, std::string> m = absl::StrSplit("a,1,b,2,c,3", ',');
>```
4. 