# minishell - tests

<details><summary>

## Notes:

</summary>

    Expansion on dollar:
    
    Dollar, followed by numbers is expanded. Numbers are considered to be words that are search in the environnement variables. Exemple:
    
```c
echo hello$1234 

OUTPUT:
hello
```

</details>

<details><summary>

## SYNTAX

</summary>

<details><summary>

#### TEST 1:

</summary>
 
 INPUT:
 
 ```c
 >
 ```
 
 OUTPUT:
 
 ```c
 bash: syntax error near unexpected token `newline'
 
 // exit status = 258
 ```
</details>

<details><summary>

#### TEST 2:

</summary>

INPUT:

```c
|
```

OUTPUT:

```c
bash: syntax error near unexpected token `|'

// exit status =258
```

</details>

<details><summary>

#### TEST 3:

</summary>
    
INPUT:

```c
>|<
```

OUTPUT: 

```c
// bash treats ">|" as on operator
// and sends error message because there is a second 
// operator "<" whitout key word
// This is the error message in bash:

syntax error near unexpected token `<'

// but in minisehll, we don't treat ">|" as a single operator, 
// so we send this error message:

minishell: syntax error near unexpected token '|'

// in both cases, the exit status is 258
```

</details>   

<details><summary>

#### TEST 4:

</summary>

INPUT:

```c
>>|<<
```

OUTPUT:

```c
syntax error near unexpected token `|'

// exit status = 258
```

</details> 

<details><summary>

#### TEST 5:

</summary>

INPUT:

```c
>>>>>>>>>>>|<<<<<<<<<<<
```

OUTPUT:

```c
syntax error near unexpected token `>>'

// exit status = 258
```

</details>
 
<details><summary>

#### TEST 6:

</summary>

INPUT:

```c
><|
```

OUTPUT:

```c
syntax error near unexpected token `<'

// exit status = 258
```

</details>

<details><summary>

#### TEST 7:

</summary>

INPUT:

```c
ls << "<" | <

```

OUTPUT:

```c
syntax error near unexpected token `newline'

// here doc is not open
// exit status = 258
```

</details>
</details>

<details><summary>

## PARSING

</summary>

<details><summary>

#### TEST 1: quotes

</summary>

Entre quotes chaque caractère est préservé

```c
ls "    -la          "
```

OUTPUT:

```c
ls:     -la          : No such file or directory
```

</details>

<details><summary>

#### TEST 2: quotes

</summary>

INPUT:

```c
"l""s"
```

```c
"l"'s'
```

```c
"""l"'s'""
```

OUTPUT:

```c
exécution normale
```

</details>
</details>


<details><summary>

## HERE DOC

</summary>


<details><summary>

#### TEST 1: keyword is unquoted

</summary>

INPUT:

```c
cat << a
```

```c
hello
$SHELL
"$SHELL"
$abc"hello
$aaa$bbb$SHELL
$?
a            // -> the right keyword
```

OUTPUT:

```c
hello
/bin/zsh
"/bin/zsh"
"hello
/bin/zsh
0
```
</details>
        
<details><summary>

#### TEST 2: keyword between quotes

</summary>

INPUT: 

```c
cat << "a"
```

```c
$SHELL$USER$HELLO
'a'
"a"
aa
aaa
"a
a"
123455
?>:"/*@
a            // -> the right keyword
```

OUTPUT:

```c
$SHELL$USER$HELLO
'a'
"a"
aa
aaa
"a
a"
123455
?>:"/*@
```

</details>


<details><summary>

#### TEST 3: keyword between quotes

</summary>

INPUT:

```c
cat << "a"a'a'
```

```c
"a"a'a'
$SHELL
$A
$USER1234
aaaabbbbcccc
>>>>>>>>
>
aaa // -> the right keyword
```

OUTPUT:

```c
"a"a'a'
$SHELL
$A
$USER1234
aaaabbbbcccc
>>>>>>>>

```
</details>
        
<details><summary>

#### TEST 4: keyword has dollar sign

</summary>

INPUT:

```c
cat << $USER
```

```c
$HELLO
$SHLVL
$SHELL
123456789
USER
$$USER    // -> I expand here
$$$$$USER // -> I expand here
"$USER"
'$USER'
$USER     // -> the right keyword
```

OUTPUT:

```c
(newline)
2
/bin/zsh
123456789
USER
$mdanchev
$$$$mdanchev
"mdanchev"
'mdanchev'
```

</details>
        
<details><summary>

#### TEST 5: keyword is `\0`

</summary>

INPUT:

```c
cat << ""
```

```c
> $HELLO
> $?
> $SHELL
>         // -> press enter -> empty line is the key word
```

OUTPUT:

```c
$HELLO
$?
$SHELL

// no expansion is performed because que key word is quoted ("\0")
```

</details>

        
<details><summary>

#### TEST 6: sequence of heredocs
        
</summary>

INPUT:

```c
<<a<<b<<c<<d<<e<<f

<<a<<b | <<c<<d |<<e | <<f
```

OUTPUT:

```c
// no output
// the .here_doc file is deleted
// if ctrl + c is pressed before exiting the last here_doc,
// the here_doc file should be deleted
// you should be able to execute another command like ls
```

</details>
        
<details><summary>

#### TEST 7: keyword is $

</summary>

INPUT:

```c
cat << $
```

```c
$SHELL
$USERNAME
$SHELL$USERNAME
$$
$$$$$$$$
$?
"$"
'$'
$             // -> the right keyword
```

OUTPUT:

```c
/bin/zsh
(newline)
/bin/zsh
$$
$$$$$$$$
1
"$"
'$'
```
</details>
        
<details><summary>

#### TEST 8: keyword is $

</summary>

INPUT:

```c
cat << $SHELL
```

```c
$$SHELL
$SHEL
$SH
SHELL
$SHELL     // -> the right keyword
```

OUTPUT:

```c
$/bin/zsh
(newline)
(newline)
SHELL
```
</details>
        
<details><summary>

#### TEST 9: expansion here doc results in a `\n`

</summary>
 
 INPUT:
 
 ```c
 cat << a
 ```
 
 ```c
 $abcde$12345
 $hello$kitty
 $hahaha
 a
 ```
 
 OUTPUT:
 
 ```c
 (newline) // because there is no environnement variable with this name
 (newline)
 (newline)
 ```
</details>
        
<details><summary>

#### TEST 10: ctrl + c

</summary>

INPUT:

```c
ls | cat << a

+ ctrl +c
```

OUTPUT:

```c
// ls should not execute
// exit status = 1
```
</details>
        
<details><summary>

#### TEST 11: expansion in heredoc

</summary>

INPUT:

```c
cat << a
```

```c
$hello?
$abc(test)
I'm$USER1234
I'm$USER!
$hello,comment$va?
a // -> key word

```

OUTPUT:

```c
?
(test)
I'm
I'mmdanchev!
,comment?
```
</details>
        
<details><summary>

#### TEST 12: commands before heredoc and signal

</summary>

INPUT:

```c
> file << eof

+ ctrl + c or + ctrl + d
```

OUTPUT:

```c
// if ctrl +c -> should not create the file
// else if ctrl + d -> creates the file
```

</details>
</details>

<details><summary>

## REDIRECTIONS

</summary>

<details><summary>

#### TEST 1: < fdin, no command

</summary>

INPUT:

```c
rm -f file1
```

```c
< file1
```

OUTPUT:

```c
minishell: file1 No such file or directory

// exit status = 1
```

</details>

<details><summary>

#### TEST 2: >, >>, fdout, no command

</summary>

INPUT:

```c
rm -f file
>> file
```

or

```c
rm -f file
> file
```

OUTPUT:

```c
// should create the file
```

</details>
        
<details><summary>

#### TEST 3: < fdin

</summary>

INPUT:

```c
rm -f file1 file2 file3 file4 
```

```c
echo a > file1
echo b > file2
echo c > file3
echo d > file4
```

```c
<file1 <file2 cat <file3 <file4
```

OUTPUT:

```c
d  // cat command should take as fdin only the last file
```

</details>
        
<details><summary>

#### TEST 4: < fdin

</summary>

INPUT:

```c
ls > file4
```

```c
<file4 wc
```

OUTPUT:

```c
29      29     280 // wc counts the number of lines
```

</details>
        
<details><summary>

#### TEST 5: > sequence of “>”

</summary>

INPUT:

```c
rm -f file1 file2 file3 file4
```

```c
ls > file1 > file2 > file3 > file4
```

OUTPUT:

```c
// only file4 should have the output
```

</details>
        
<details><summary>

#### TEST 6: >  test on TRUNC

</summary>

INPUT:

```c
echo "coucou comment sa va" > file4
```

```c
uname > file4
```

```c
cat file4
```

OUTPUT:

```c
// all the previous content should be deleted and replaced by the new ouput
```

</details>
        
<details><summary>

#### TEST 7: >> fdout

</summary>

INPUT:

```c
rm -f file1 file2 file3 file4
```

```c
echo coucou >>file1 >> file2 >>     file3 >>            file4
```

```c
cat file1
cat file2
cat file3
cat file4
```

OUTPUT:

```c
// all files were created
// only file4 has "coucou"
```

</details>
        
<details><summary>

#### TEST 8: combination of < and <<

</summary>

INPUT:

```c
rm -f file
```

```c
uname > file
```

```c
< file
```

```c
< file << EOF
```

OUTPUT:

```c
// should open the here doc file
// no output
```

</details>
        
<details><summary>

#### TEST 9: combination of < and <<

</summary>

INPUT:

```c
rm -f file
```

```c
< file << eof
```

Write something in the here doc. Exemple:

```c
test
eof // -> keyword
```

OUTPUT:

```c
minishell: file No such file or directory

// exit status = 1
```

</details>
        
<details><summary>

#### TEST 10: combination of < and <<

</summary>

INPUT:

```c
rm -f file
```

```c
< file << eof
```

```c
+ ctrl  + c 
```

OUTPUT:

```c
^C 
// there is no message "file not found"
// exit status is 1
```

</details>
        
<details><summary>

#### TEST 11: combination of < , > and >>
        
</summary>

INPUT:

```c
rm -f file1 file2 file3
```

```c
ls > file1
```

```c
< file1 wc > file2 >> file3
```

OUTPUT:

```c
// only file3 has the output of the command wc
```

</details>
        
<details><summary>

#### TEST 12: `\0`

</summary>

INPUT:

```c
ls < ""
```

OUTPUT:

```c
minishell:  No such file or directory

//exit status = 1
```

</details>
        
<details><summary>

#### TEST 13: `\0`

</summary>
 
 INPUT:
 
 ```c
  "" < ""
 ```
 
 OUTPUT:
 
 ```c
 minishell:  No such file or directory
 
 //exit status = 1
 ```
 
</details>

<details><summary>

#### TEST 14: `\0`

</summary>

INPUT:

```c
rm -f file
```

```c
 "" < file
```

OUTPUT:

```c
minishell: file: No such file or directory

// exit status = 1
// file is not created
```

</details>
        
<details><summary>

#### TEST 15: `\0`

</summary>

INPUT:

```c
rm -f file
```

```c
 "" > file
```

OUTPUT:

```c
minishell: : command not found

// exit status = 127
// file is created
```

</details>
        
<details><summary>

#### TEST 16: expansion

</summary>

INPUT:

```c
> hello$coucou
```

or

```c
>> hello$coucou
```

OUTPUT:

```c
// should create a file called "hello"
// exit status = 0
```

</details>
        
<details><summary>

#### TEST 17: expansion

</summary>
 
 INPUT:
 
 ```c
 > $aaaa$bb"b"bb$ccc
 ```
 
 or
 
 ```c
 >> $aaaa$bb"b"bb$ccc
 ```
 
 OUTPUT:
 
 ```c
 // should create a file called "bbb"
 // exit status = 0
 ```

</details>
        
<details><summary>

#### TEST 18: expansion

</summary>
 
 INPUT:
 
 ```c
 > $aaaa$bb"b"bb$cc'c'
 ```
 
 or
 
 ```c
 >> $aaaa$bb"b"bb$cc'c'
 ```
 
 OUTPUT:
 
 ```c
 // should create a file called "bbbc"
 // exit status = 0
 ```

</details>
</details>
        

<details><summary>
## AMBIGIOUS REDIRECTION

</summary>

<details><summary>

#### TEST 1:

</summary>

INPUT:

```c
ls < $a
```

or

```c
< $a ls
```

OUTPUT:

```c
ambiguous redirect

// exit status = 1
```

</details>
        
<details><summary>

#### TEST 2:

</summary>

INPUT:

```c
ls < $a
```

or

```c
ls > $a

```

or

```c
ls >> $a
```

OUTPUT:

```c
ambiguous redirect

// exit status = 1
```
</details>
        
<details><summary>

#### TEST 3:

</summary>

INPUT:

```c
ls < $abc$efg$hijk
```

or

```c
ls > $abc$efg$hijk

```

or

```c
ls >> $abc$efg$hijk
```

OUTPUT:

```c
ambiguous redirect

// exit status = 1
```
</details>
        
<details><summary>

#### TEST 4:

</summary>

INPUT:

```c
rm -f file
```

```c
> file < $a ls
```

OUTPUT:

```c
ambiguous redirect

// exit status = 1
// "file" is created and is empty
```
</details>
        
<details><summary>

#### TEST 5:

</summary>

INPUT:

```c
rm -f file
```

```c
> file cat | ls < $a
```

OUTPUT:

```c
ambiguous redirect

// exit status = 1
// "file" is created and is empty
// cat acts like bloking command
// you can press enter
```

</details>
</details>

- BUILTINS
    - TEST 1: SHLVL
        
        INPUT:
        
        ```c
        export SHLVL=54
        ```
        
        Open new minishell:
        
        ```c
        ./minishell
        ```
        
        In this second minishell execute env:
        
        ```c
        env
        ```
        
        OUTPUT:
        
        ```c
        // The SHLVL should be 55
        ```
        
    - TEST 2: SHLVL
        
        INPUT:
        
        ```c
        unset SHLVL
        ```
        
        Open new minishell:
        
        ```c
        ./minishell
        ```
        
        In this second minishell execute env:
        
        ```c
        env
        ```
        
        OUTPUT:
        
        ```c
        // The SHLVL should be set to one
        ```
        
    - TEST 3: SHLVL
        
        INPUT:
        
        ```c
        export SHLVL=98a
        ```
        
        Open new minishell:
        
        ```c
        ./minishell
        ```
        
        In this second minishell execute env:
        
        ```c
        env
        ```
        
        OUTPUT:
        
        ```c
        // The SHLVL should be set to one
        ```
        
    - TEST 4: SHLVL
        
        INPUT:
        
        ```c
        export SHLVL=hello
        ```
        
        Open new minishell:
        
        ```c
        ./minishell
        ```
        
        In this second minishell execute env:
        
        ```c
        env
        ```
        
        OUTPUT:
        
        ```c
        // The SHLVL should be set to one
        ```
        
    - TEST 5: echo
        
        INPUT:
        
        ```c
        echo -n -n -n -n -n -n hello
        ```
        
        OUTPUT:
        
        ```c
        hellominishell$
        
        //exit status = 0
        ```
        
    - TEST 6: echo
        
        INPUT:
        
        ```c
        echo coucou comment sa va
        ```
        
        OUTPUT:
        
        ```c
        coucou comment sa va
        ```
        
    - TEST 7: exit
        
        INPUT:
        
        ```c
        exit 56
        ```
        
        OUTPUT:
        
        ```c
        // exit status is 56
        ```
        
    - TEST 8: exit, int max
        
        INPUT:
        
        ```c
        exit 2147483647
        ```
        
        or
        
        ```c
        exit +2147483647
        ```
        
        OUTPUT:
        
        ```c
        // exit status is 255
        ```
        
    - TEST 9: exit, int max + 1
        
        INPUT:
        
        ```c
        exit 2147483648
        ```
        
        or
        
        ```c
        exit +2147483648
        ```
        
        OUTPUT:
        
        ```c
        // exit status is 0
        ```
        
    - TEST 10: exit, int min
        
        INPUT:
        
        ```c
        exit -2147483648
        ```
        
        OUTPUT:
        
        ```c
        // exit status is 0
        ```
        
    - TEST 11: exit, int min - 1
        
        INPUT:
        
        ```c
        exit -2147483649
        ```
        
        OUTPUT:
        
        ```c
        // exit status is 255
        ```
        
    - TEST 12: exit, long max
        
        INPUT:
        
        ```c
        exit 9223372036854775807
        ```
        
        or
        
        ```c
        exit +9223372036854775807
        ```
        
        OUTPUT:
        
        ```c
        // exit status is 255
        ```
        
    - TEST 13: exit, long max + 1
        
        INPUT:
        
        ```c
        exit 9223372036854775808
        ```
        
        or
        
        ```c
        exit +9223372036854775808
        ```
        
        OUTPUT:
        
        ```c
        exit
        minishell: exit: 9223372036854775808: numeric argument required
        // exit status is 255
        ```
        
    - TEST 14: exit, long min
        
        INPUT:
        
        ```c
        exit -9223372036854775808
        ```
        
        OUTPUT:
        
        ```c
        // exit status = 0
        ```
        
    - TEST 15: exit, long min - 1
        
        INPUT:
        
        ```c
        exit -9223372036854775809
        ```
        
        OUTPUT:
        
        ```c
        minishell: exit: -9223372036854775809: numeric argument required
        // exit status = 255
        ```
        
    - TEST 15: exit, spaces in string
        
        INPUT:
        
        ```c
        exit "       123        "
        ```
        
        OUTPUT:
        
        ```c
        // exit status = 123
        ```
        
    - TEST 16: exit, spaces in string
        
        INPUT:
        
        ```c
        exit "       1 23        "
        ```
        
        OUTPUT:
        
        ```c
        exit
        minishell: exit:        1 23        : numeric argument required
        
        // exit status = 255
        ```
        
    - TEST 17: exit, not a int
        
        INPUT:
        
        ```c
        exit 123a4
        ```
        
        or
        
        ```c
        exit "       123a4        "
        ```
        
        or
        
        ```c
        exit "       123        a4"
        ```
        
        OUTPUT:
        
        ```c
        exit
        minishell$: exit 123a4
        
        exit
        minishell: exit: 123a4: numeric argument required
        
        exit
        minishell: exit:        123a4        : numeric argument required
        
        exit
        minishell: exit:        123        a4: numeric argument required
        
        // exit status = 255
        ```
        
    - TEST 18: not a numeric argument
        
        INPUT:
        
        ```c
        exit hello
        ```
        
        OUTPUT:
        
        ```c
        exit
        minishell: exit: hello: numeric argument required
        
        // exit status = 255
        ```
        
    - TEST 19: too many arguments argument
        
        INPUT:
        
        ```c
        exit 54 65 85
        ```
        
        or
        
        ```c
        exit 54 hello
        ```
        
        OUTPUT:
        
        ```c
        exit
        minishell: exit: too many arguments
        
        // exit status = 1
        // DOESNT EXIT THE SHELL
        ```
        
    - TEST 20: too many arguments argument
        
        INPUT:
        
        ```c
        exit hello 54
        ```
        
        OUTPUT:
        
        ```c
        exit
        minishell: exit: hello: numeric argument required
        
        // exit status = 255
        // EXITS THE SHELL
        ```
        
    - TEST 21: negative values
        
        INPUT:
        
        ```c
        exit -214
        ```
        
        OUTPUT:
        
        ```c
        exit
        
        // exit status = 42
        ```
        
- PIPES
    - TEST 1: two blocking commands, zombies
        
        INPUT:
        
        ```c
        cat | cat
        
        + ctr + \
        ```
        
        OUTPUT:
        
        ```c
        ^\Quit: 3
        
        // exit status = 131
        // no zombies
        ```
        
    - TEST 2: two blocking commands, zombies
        
        INPUT:
        
        ```c
        cat | cat
        
        + ctr + c
        ```
        
        OUTPUT:
        
        ```c
        ^C
        
        // exit status = 130
        // no zombies
        ```
        
    - TEST 3: two blocking commands
        
        INPUT:
        
        ```c
        cat | cat
        
        + ctr + d
        ```
        
        OUTPUT:
        
        ```c
        // no output, there is only prompt
        // exit status 0
        // no zombies
        ```
        
    - TEST 4 three pipes, one redirection
        
        INPUT:
        
        ```c
        rm -f file file1 file2 file3 file4 file5 file6
        ```
        
        Insert some text in file1. This text repeats the name Max multiple times.
        
        ```c
        
        echo "Une journée ensoleillée, un chien nommé Max. Max aimait courir, courir sans arrêt. Son énergie était débordante. Il courait dans le parc, courait dans la rue, courait partout où ses pattes le portaient. Max était un véritable tourbillon de mouvement. Rien ne pouvait le ralentir. Max était un chien infatigable, toujours en mouvement, toujours en train de courir." >> file1
        ```
        
         "Une journée ensoleillée, un chien nommé **Max**. **Max** aimait courir, courir sans arrêt. Son énergie était débordante. Il courait dans le parc, courait dans la rue, courait partout où ses pattes le portaient. **Max** était un véritable tourbillon de mouvement. Rien ne pouvait le ralentir. **Max** était un chien infatigable, toujours en mouvement, toujours en train de courir." 
        
        Count the number of occurrences of the name Max.
        
        ```c
        
        cat file1 | tr '[:upper:]' '[:lower:]' | tr -cs '[:alpha:]' '\n' | grep -c 'max'
        ```
        
        OUTPUT:
        
        ```c
        4
        ```
        
    - TEST 5: two pipes, one redirection
        
        INPUT:
        
        ```c
        rm -f file file1 file2 file3 file4 file5 file6
        ```
        
        Insert some text in file1. This text repeats the name Max 4 times.
        
        ```c
        
        echo "Une journée ensoleillée, un chien nommé Max. Max aimait courir, courir sans arrêt. Son énergie était débordante. Il courait dans le parc, courait dans la rue, courait partout où ses pattes le portaient. Max était un véritable tourbillon de mouvement. Rien ne pouvait le ralentir. Max était un chien infatigable, toujours en mouvement, toujours en train de courir." >> file1
        ```
        
         "Une journée ensoleillée, un chien nommé **Max**. **Max** **aimait** 
        
        courir, courir sans arrêt. Son énergie était débordante. Il courait dans le parc, courait dans la rue, courait partout où ses pattes le portaient. **Max** était 
        
        un véritable tourbillon de mouvement. Rien ne pouvait le ralentir. **Max** était 
        
        un chien infatigable, toujours en mouvement, toujours en train de courir." 
        
        Print the first word after each occurence of Max and sort it in alphabetic order
        
        ```c
        
        grep -o -i 'Max \w*' file1 | awk '{print $2}' | sort
        ```
        
        OUTPUT:
        
        ```c
        aimait
        était
        était
        ```
        
    - TEST 5: ten pipes, one redirection
        
        INPUT:
        
        ```c
        rm -f file file1 file2 file3 file4 file5 file6
        ```
        
        Insert some text in file1. This text repeats the name Max 4 times.
        
        ```c
        
        echo "Une journée ensoleillée, un chien nommé Max. Max aimait courir, courir sans arrêt. Son énergie était débordante. Il courait dans le parc, courait dans la rue, courait partout où ses pattes le portaient. Max était un véritable tourbillon de mouvement. Rien ne pouvait le ralentir. Max était un chien infatigable, toujours en mouvement, toujours en train de courir." >> file1
        ```
        
        Print the first word after each occurence of Max and sort it in alphabetic order
        
        ```c
        
        cat < file1 | grep -i "Max" | sed 's/[^a-zA-Z ]//g' | tr '[:upper:]' '[:lower:]' | tr ' ' '\n' | sort | uniq -c | sort -nr | head -n 10
        ```
        
        Explanation of the command:
        
        1. **`cat file1`**: Displays the content of the text file.
        2. **`grep -i "Max"`**: Searches for all occurrences of the word "word" (ignoring case).
        3. **`sed 's/[^a-zA-Z ]//g'`**: Removes all non-alphabetic characters, except spaces.
        4. **`tr '[:upper:]' '[:lower:]'`**: Converts all characters to lowercase.
        5. **`tr ' ' '\n'`**: Replaces spaces with line breaks.
        6. **`sort`**: Sorts the words in alphabetical order.
        7. **`uniq -c`**: Counts the number of occurrences for each word.
        8. **`sort -nr`**: Sorts the words in descending order of frequency.
        9. **`head -n 10`**: Displays the first 10 lines (the most frequent words).
        
        OUTPUT:
        
        ```c
        	 4 max
           3 un
           3 tait
           3 le
           3 courir
           3 courait
           2 toujours
           2 mouvement
           2 en
           2 de
        ```
        
    - TEST 6: multiple cat
        
        INPUT:
        
        ```c
        cat << a | cat << b | cat << c
        ```
        
        ```c
        coucou
        a       // first key word
        hello
        b      // second key word
        + ctr + c
        ```
        
        OUTPUT:
        
        ```c
        // no output, only promt
        // exit status is 1
        // all here doc files are deleted
        ```
        
    - TEST 7: cat | ls, zombies
        
        INPUT:
        
        ```c
        cat | ls
        ```
        
        ```c
        + ctrl + \
        ```
        
        OUTPUT:
        
        ```c
        // ls executes normally 
        ^/minishell: 
        
        // exit status = 0
        // no zombies
        ```
        
    - TEST 8: cat | ls, zombies
        
        INPUT:
        
        ```c
        cat | ls
        ```
        
        ```c
        + ctrl + c
        ```
        
        OUTPUT:
        
        ```c
        // ls executes normally
        ^C
        minishell: 
        
        // exit status = 0
        // no zombies
        ```
        
    - TEST 9: pipes, expansion and redirections
        
        INPUT:
        
        ```c
        rm -f file1
        ```
        
        ```c
        echo "$USER has logged at:" > file1 | w | awk 'NR>2 {print $4}' >> file1
        ```
        
        ```c
        cat file1
        ```
        
        OUTPUT:
        
        ```c
        mdanchev has logged at:
        9:06
        ```
        
- SIGNALS
    - To send a signal to a single process:
        1. Check the pid of the process you want to kill with the command:
        
        ```c
        ps
        ```
        
        1. Then send the signal you 
        
        ```c
        kill -[signal] PID
        kill -[signal_suffix] PID
        kill -[sig_num] PID
        
        // EXEMPLE FOR SIGTERM
        kill -SIGTERM PID
        kill -TERM PID
        kill -15 PID 
        ```
        
    - TEST 1:
        
        INPUT:
        
        ```c
        cat | ls
        ```
        
        ```c
        + ctrl + c or ctrl + \
        ```
        
        OUTPUT:
        
        ```c
        // executes ls and exit with status 0 after recieving the signal
        // no zombies
        ```
        
    - TEST 2:
        
        INPUT:
        
        ```c
        cat | ls
        ```
        
        ```c
        + enter
        ```
        
        OUTPUT:
        
        ```c
        // executes ls and exit with status 0
        // no zombies
        ```
        
    - TEST 3:
        
        INPUT:
        
        ```c
        cat | cat
        ```
        
        ```c
        + ctr + c or + ctrl + \
        ```
        
        OUTPUT:
        
        ```c
        ^\Quit: 3 // for ctr + \, exit status = 131
        
        ^C // for ctrl + c, exit status 130
        
        //no zombies
        ```
        
- ZOMBIES TESTS
    
    A zombie process refers to a process that has completed its execution but still has its entry in the process table, as it has not yet been fully removed by the parent process. This situation typically occurs when the parent process has not yet called the "wait()" or "waitpid()" system call to retrieve the exit status of the child process.
    
    When a process finishes its execution, it leaves behind system resources such as file descriptors, process identifiers, and data structures. It is the responsibility of the parent process to clean up these resources to avoid resource leaks. **If the parent process fails to retrieve this information, the child process becomes a zombie process.**
    
    A zombie process is not actively running, but it still occupies an entry in the operating system's process table. As long as the zombie process exists, it prevents the allocation of system resources to other processes.
    
    To check for zombies, use the commands:
    
    ```c
    ps -j
    ```
    
    or:
    
    ```c
    ps aux | grep defunct
    ```
    
    If the name of the process appears in brakets and you see ‘m
