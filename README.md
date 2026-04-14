# Лабораторная работа № 2
<<<<<<< HEAD

Данная лабораторная работа посвещена изучению систем контроля версий на примере **Git**.

## Туториал работы
Настроим переменные, необходимые для работы, переместимся в рабочую директорию и выполним активацию предварительно созданных скриптов.

```sh
=======
Данная лабораторная работа посвещена изучению систем контроля версий на примере **Git**.
## Туториал работы
Настроим переменные, необходимые для работы, переместимся в рабочую директорию и выполним активацию предварительно созданных скриптов.
```bash
>>>>>>> 13d0abda3572ab036e1a6eff085baad7539519d0
$ export GITHUB_USERNAME=Nicckki
$ export GITHUB_EMAIL=<почтовый_ящик
$ export GITHUB_TOKEN=<мой_токен>
$ alias edit=nano
$ cd ${GITHUB_USERNAME}/workspace
$ source scripts/activate
```
<<<<<<< HEAD
Здесь мы создаем конфигурационный файл для утилиты **hub**, в котором хранятся логин и токен для доступа к GitHub, а также глобально настраиваем Git на использование протокола "https".

```sh
=======
Здесь мы создаем конфигурационный файл для утилиты hub, в котором хранятся логин и токен для доступа к GitHub, а также глобально настраиваем Git на использование протокола "https".
```bash
>>>>>>> 13d0abda3572ab036e1a6eff085baad7539519d0
$ mkdir ~/.config
$ cat > ~/.config/hub <<EOF
github.com:
- user: ${GITHUB_USERNAME}
  oauth_token: ${GITHUB_TOKEN}
  protocol: https
EOF
$ git config --global hub.protocol https
```
<<<<<<< HEAD

```sh
$ mkdir projects/lab02 && cd projects/lab02
$ git init
$ git config --global user.name ${GITHUB_USERNAME}
$ git config --global user.email ${GITHUB_EMAIL}
# check your git global settings
$ git config -e --global
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab02.git
$ git pull origin master
$ touch README.md
$ git status
$ git add README.md
$ git commit -m"added README.md"
$ git push origin master
```

Добавить на сервисе **GitHub** в репозитории **lab02** файл **.gitignore**
со следующем содержимом:

```sh
*build*/
*install*/
*.swp
.idea/
```

```sh
$ git pull origin master
$ git log
```

```sh
=======
Создаем папку для 2 лабораторной работы и перемещаемся в неё.
```bash
$ mkdir projects/lab02 && cd projects/lab02
```
Создаём новый пустой Git-репозиторий в текущей папке.
```bash
$ git init
```
<details>
  <summary>Вывод команды говорит нам, что ветка называется "master"</summary>
  
    hint: Using 'master' as the name for the initial branch. This default branch name
    hint: is subject to change. To configure the initial branch name to use in all
    hint: of your new repositories, which will suppress this warning, call:
    hint: 
    hint: 	git config --global init.defaultBranch <name>
    hint: 
    hint: Names commonly chosen instead of 'master' are 'main', 'trunk' and
    hint: 'development'. The just-created branch can be renamed via this command:
    hint: 
    hint: 	git branch -m <name>
    Initialised empty Git repository in /home/vboxuser/Nicckki/workspace/projects/lab02/.git/
</details>

Поскольку на GitHub основная ветка по умолчанию называется main, во избежание конфликта имен переименуем локальную ветку master в main.

```bash
$ git branch -m main
```
Устанавливаем имя и почту для гита и проверяем, чтобы все получилось правильно
```bash
$ git config --global user.name ${GITHUB_USERNAME}
$ git config --global user.email ${GITHUB_EMAIL}
$ git config -e --global
```
<details>
  <summary>Вывод говорит нам, что все установилось правильно</summary>

    [hub]
        protocol = https
    [user]
        name = Nicckki
        email = <моя почта>@gmail.com
</details>
Все настроено корректно, теперь привяжем локальную папку к удаленному репозиторию и загрузим все на наш компьютр, что есть репозитории.

```bash  
$ git remote add origin https://github.com/${GITHUB_USERNAME}/lab02.git
$ git pull origin master
```

<details>
  <summary>Вывод команды, что все успешно</summary>
  
    remote: Enumerating objects: 3, done.
    remote: Counting objects: 100% (3/3), done.
    remote: Compressing objects: 100% (2/2), done.
    remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
    Unpacking objects: 100% (3/3), 1.45 KiB | 740.00 KiB/s, done.
    From https://github.com/Nicckki/lab02
     * branch            main       -> FETCH_HEAD
     * [new branch]      main       -> origin/main
</details>

Создадим README.md и смотрим статусы файлов в папке
```bash
$ touch README.md
$ git status
```
<details>
  <summary>Статус показывает, что новый README.md пока не добавлен в репозиторий.</summary>
    
    On branch main
     Untracked files:
      (use "git add <file>..." to include in what will be committed)
  	  README.md
  
    nothing added to commit but untracked files present (use "git add" to track)
</details>
 Добавим его и сделаем коммит.
 
```bash
$ git add README.md
$ git commit -m"added README.md"
```
<details>
  <summary>Команда выполнена успешно.</summary>
  
    [main 307ba30] added README.md
    1 file changed, 0 insertions(+), 0 deletions(-)
    create mode 100644 README.md
</details>
Теперь можно отправить локальный коммит в удаленный репозиторий.

```bash
$ git push origin main
```
<details>
  <summary>На GitHub высветился README, значит мы все сделали верно.</summary>

    Username for 'https://github.com': Nicckki
    Password for 'https://Nicckki@github.com': 
    Enumerating objects: 4, done.
    Counting objects: 100% (4/4), done.
    Compressing objects: 100% (2/2), done.
    Writing objects: 100% (3/3), 281 bytes | 281.00 KiB/s, done.
    Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
    To https://github.com/Nicckki/lab02.git
       70a9e11..307ba30  main -> main
</details>
Теперь создадим .gitignore на GitHub и загрузим к нам.

```bash
$ git pull origin main
```
<details>
  <summary>.gitignore загрузился</summary>
  
    remote: Enumerating objects: 4, done.
    remote: Counting objects: 100% (4/4), done.
    remote: Compressing objects: 100% (2/2), done.
    remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
    Unpacking objects: 100% (3/3), 991 bytes | 330.00 KiB/s, done.
    From https://github.com/Nicckki/lab02
     * branch            main       -> FETCH_HEAD
     307ba30..029fd75  main       -> origin/main
    Updating 307ba30..029fd75
    Fast-forward
     .gitignore | 4 ++++
     1 file changed, 4 insertions(+)
     create mode 100644 .gitignore
</details>
Смотрим на историю работы в репозитории.

```bash
$ git log
```
<details>
  <summary>Видно, что первый и третий коммит был сделан мною на гитхабе, второй в консоли.</summary>
  
    commit 029fd758ff7d9ca433c4efb17f919eddfa8f9613 (HEAD -> main, origin/main)
    Author: Kuzin Nikolai <87363911+Nicckki@users.noreply.github.com>
    Date:   Tue Apr 14 15:32:04 2026 +0300

      Create .gitignore

    commit 307ba30012df042578aea3dc30036cf27e2bc0af
    Author: Nicckki <nkuzin279@gmail.com>
    Date:   Tue Apr 14 15:20:12 2026 +0300

      added README.md

    commit 70a9e111890f89986ff5c5497fe56034cc6d3f03
    Author: Kuzin Nikolai <87363911+Nicckki@users.noreply.github.com>
    Date:   Tue Apr 14 15:09:29 2026 +0300

      Initial commit
</details>

Теперь создадим несколько .cpp файлов(sources, include, examples)

```bash
>>>>>>> 13d0abda3572ab036e1a6eff085baad7539519d0
$ mkdir sources
$ mkdir include
$ mkdir examples
$ cat > sources/print.cpp <<EOF
#include <print.hpp>

void print(const std::string& text, std::ostream& out)
{
  out << text;
}

void print(const std::string& text, std::ofstream& out)
{
  out << text;
}
EOF
```
<<<<<<< HEAD

```sh
=======
```bash
>>>>>>> 13d0abda3572ab036e1a6eff085baad7539519d0
$ cat > include/print.hpp <<EOF
#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ofstream& out);
void print(const std::string& text, std::ostream& out = std::cout);
EOF
```
<<<<<<< HEAD

```sh
=======
```bash
>>>>>>> 13d0abda3572ab036e1a6eff085baad7539519d0
$ cat > examples/example1.cpp <<EOF
#include <print.hpp>

int main(int argc, char** argv)
{
  print("hello");
}
EOF
```
<<<<<<< HEAD

```sh
=======
```bash
>>>>>>> 13d0abda3572ab036e1a6eff085baad7539519d0
$ cat > examples/example2.cpp <<EOF
#include <print.hpp>

#include <fstream>

int main(int argc, char** argv)
{
  std::ofstream file("log.txt");
  print(std::string("hello"), file);
}
EOF
```
<<<<<<< HEAD

```sh
$ edit README.md
```

```sh
$ git status
=======
Фиксируем и отправляем изменения.

```bash
>>>>>>> 13d0abda3572ab036e1a6eff085baad7539519d0
$ git add .
$ git commit -m"added sources"
$ git push origin master
```
Смотрим что выведет команда.
<details>
  <summary>Все успешно было сохранени на GitHub.</summary>
  
    [main a34c9a4] added sources
     5 files changed, 33 insertions(+)
     create mode 100644 examples/example1.cpp
     create mode 100644 examples/example2.cpp
     create mode 100644 include/print.hpp
     create mode 100644 sources/print.cpp

</details>

# Домашняя работа
## Часть 1
### Пункт 1 Создайте пустой репозиторий на сервисе github.com (или gitlab.com, или bitbucket.com).
Поскольку пустой репозиторий lab02 уже был создан на GitHub в начале работы (в соответствии с заданием Tutorial), повторное создание не требуется. Переходим сразу к пункту 3.
### Пункт 3 Создайте файл hello_world.cpp в локальной копии репозитория (который должен был появиться на шаге 2). Реализуйте программу Hello world на языке C++ используя плохой стиль кода. Например, после заголовочных файлов вставьте строку using namespace std;.
Создаем файл:

```bash
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    return 0;
}
EOF
```
### Пункт 4 Добавьте этот файл в локальную копию репозитория.

```bash
git add hello_world.cpp
```
### Пункт 5 Закоммитьте изменения с осмысленным сообщением.

```bash
git commit -m "Add hello_world.cpp with bad style"
```
<details>
  <summary>Вывод</summary>

      [main 8f224a5] Add hello_world.cpp with bad style
     1 file changed, 7 insertions(+)
     create mode 100644 hello_world.cpp
</details>

### Пункт 6 Изменитьте исходный код так, чтобы программа через стандартный поток ввода запрашивалось имя пользователя. А в стандартный поток вывода печаталось сообщение Hello world from @name, где @name имя пользователя.
Новый код:

```bash
cat > hello_world.cpp <<EOF
#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello world from " << name << "!" << endl;
    return 0;
}
EOF
```
### Пункт 7 Закоммитьте новую версию программы. Почему не надо добавлять файл повторно git add?

```bash
git commit -am "Add name input to hello_world"
```
Что делает флаг -a: Автоматически добавляет измененные файлы (которые уже отслеживаются Git). Новые файлы он не добавит. Почему не нужен git add: Файл hello_world.cpp уже отслеживается Git (мы его добавили в шаге 2). Флаг -a заменяет git add для уже существующих файлов.

### Пункт 8
фвфв









