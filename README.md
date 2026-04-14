# Лабораторная работа № 2
Данная лабораторная работа посвещена изучению систем контроля версий на примере **Git**.

## Туториал работы
Настроим переменные, необходимые для работы, переместимся в рабочую директорию и выполним активацию предварительно созданных скриптов.
```bash
$ export GITHUB_USERNAME=Nicckki
$ export GITHUB_EMAIL=<почтовый_ящик
$ export GITHUB_TOKEN=<мой_токен>
$ alias edit=nano
$ cd ${GITHUB_USERNAME}/workspace
$ source scripts/activate
```
Здесь мы создаем конфигурационный файл для утилиты **hub**, в котором хранятся логин и токен для доступа к GitHub, а также глобально настраиваем Git на использование протокола "https".

```bash
$ mkdir ~/.config
$ cat > ~/.config/hub <<EOF
github.com:
- user: ${GITHUB_USERNAME}
  oauth_token: ${GITHUB_TOKEN}
  protocol: https
EOF
$ git config --global hub.protocol https
```
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
Фиксируем и отправляем изменения.

```bash
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

### Пункт 8 Запуште изменения в удалёный репозиторий.

```bash
git push origin main
```
<details>
  <summary>Вывод команды.</summary>

    Username for 'https://github.com': Nicckki
    Password for 'https://Nicckki@github.com': 
    Enumerating objects: 17, done.
    Counting objects: 100% (17/17), done.
    Compressing objects: 100% (13/13), done.
    Writing objects: 100% (13/13), 3.37 KiB | 1.68 MiB/s, done.
    Total 13 (delta 7), reused 0 (delta 0), pack-reused 0
    remote: Resolving deltas: 100% (7/7), completed with 2 local objects.
    To https://github.com/Nicckki/lab02.git
       13d0abd..dbdd3c3  main -> main
</details>

### Пункт 9 Проверьте, что история коммитов доступна в удалёный репозитории.

```bash
git log
```
<details>
      <summary>Вывод команды.</summary>
  
    commit da737f14b7e0b741e2681d58dfb6b79cac7aef71
    Author: Nicckki <nkuzin279@gmail.com>
    Date:   Tue Apr 14 18:44:38 2026 +0300
    
        Add name input to hello_world
    
    commit 8f224a5b4b9b7371f1e62e6c484e40dad4d9019f
    Author: Nicckki <nkuzin279@gmail.com>
    Date:   Tue Apr 14 18:29:55 2026 +0300
    
        Add hello_world.cpp with bad style

</details>

## Часть 2
### Пункт 1 В локальной копии репозитория создайте локальную ветку patch1.

```bash
git checkout -b patch1
```

### Пункт 2 Внесите изменения в ветке patch1 по исправлению кода и избавления от using namespace std;.
Меняем только код hello_world.cpp

```bash
#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << "!" << std::endl;
    return 0;
}
```
### Пункт 3 commit, push локальную ветку в удалённый репозиторий.

```bash
git commit -am "Remove using namespace std"
```
<details>
  <summary>Вывод</summary>

      [patch1 eaa79f1] Remove using namespace std
     1 file changed, 4 insertions(+), 6 deletions(-)
</details>

```bash
git push origin patch1
```
<details>
  <summary>Вывод</summary>

        Username for 'https://github.com': Nicckki
      Password for 'https://Nicckki@github.com': 
      Enumerating objects: 92, done.
      Counting objects: 100% (92/92), done.
      Compressing objects: 100% (84/84), done.
      Writing objects: 100% (92/92), 28.09 KiB | 1.08 MiB/s, done.
      Total 92 (delta 44), reused 0 (delta 0), pack-reused 0
      remote: Resolving deltas: 100% (44/44), done.
      remote: 
      remote: Create a pull request for 'patch1' on GitHub by visiting:
      remote:      https://github.com/Nicckki/lab02/pull/new/patch1
      remote: 
      To https://github.com/Nicckki/lab02.git
       * [new branch]      patch1 -> patch1
</details>

### Пункт 4 Проверьте, что ветка patch1 доступна в удалёный репозитории.
```bash
git log
```
<details>
  <summary>В выводе видно как фигурирует origin/patch1</summary>

      commit eaa79f1e89d05535ec5fb646b34e08d198017246 (HEAD -> patch1, origin/patch1)
    Author: Nicckki <nkuzin279@gmail.com>
    Date:   Tue Apr 14 19:37:09 2026 +0300

    Remove using namespace std
</details>

### Пункт 5 Создайте pull-request patch1 -> master.
Создаем pull-request patch1 -> main на GitHub через терминал.(так быстро и просто)

```bash
hub pull-request -b main -h patch1 -m "Fix: remove using namespace std"
```
В итоге высветилась ссылка на созданный pull request "https://github.com/Nicckki/lab02/pull/1"

### Пункт 6 В локальной копии в ветке patch1 добавьте в исходный код комментарии.
Добавляем комментарии:
```bash
#include <iostream>  // для ввода-вывода
#include <string>    // для работы со строками

int main() {
    std::string name;  // переменная для хранения имени пользователя
    std::cout << "Enter your name: ";  // запрос имени
    std::cin >> name;  // чтение имени из консоли
    std::cout << "Hello world from " << name << "!" << std::endl;  // приветствие
    return 0;  // успешное завершение программы
}
```
### Пункт 7 commit, push.
Коммитим и пушим изменения.
```bash
git commit -am "Add comments to hello_world.cpp"
```
<details>
  <summary>Вывод</summary>

    [patch1 56cdb34] Add comments to hello_world.cpp
     1 file changed, 12 insertions(+), 12 deletions(-)
</details>

```bash
git push origin patch1
```
<details>
  <summary>Вывод</summary>

    Username for 'https://github.com': Nicckki
    Password for 'https://Nicckki@github.com': 
    Enumerating objects: 5, done.
    Counting objects: 100% (5/5), done.
    Compressing objects: 100% (3/3), done.
    Writing objects: 100% (3/3), 569 bytes | 569.00 KiB/s, done.
    Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
    remote: Resolving deltas: 100% (1/1), completed with 1 local object.
    To https://github.com/Nicckki/lab02.git
       eaa79f1..56cdb34  patch1 -> patch1
  </details>

 ### Пункт 8 Проверьте, что новые изменения есть в созданном на шаге 5 pull-request
Этот момент я выполнил в гитхабе, открыл ссылку и прокрутил вниз, где вкладка **commits** показала оба коммита.

### Пункт 9 В удалённый репозитории выполните слияние PR patch1 -> master и удалите ветку patch1 в удаленном репозитории.
Также сделали на гитхабе.

### Пункт 10 Локально выполните pull.

```bash
git checkout main
git pull origin main
```
<details>
  <summary>Вывод</summary>

    remote: Enumerating objects: 15, done.
    remote: Counting objects: 100% (14/14), done.
    remote: Compressing objects: 100% (11/11), done.
    remote: Total 11 (delta 7), reused 0 (delta 0), pack-reused 0 (from 0)
    Unpacking objects: 100% (11/11), 4.53 KiB | 244.00 KiB/s, done.
    From https://github.com/Nicckki/lab02
     * branch            main       -> FETCH_HEAD
       e894b99..ab3f56f  main       -> origin/main
    Updating e894b99..ab3f56f
    Fast-forward
     README.md       | 81 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
     hello_world.cpp | 16 +++++++---------
     2 files changed, 88 insertions(+), 9 deletions(-)
  </details>

  ### Пункт 11 С помощью команды git log просмотрите историю в локальной версии ветки main.
```bash
git log --oneline
```
<details>
  <summary>Вывод</summary>
  
    ab3f56f (HEAD -> main, origin/main) Merge pull request #1 from Nicckki/patch1
    56cdb34 (origin/patch1, patch1) Add comments to hello_world.cpp
    eaa79f1 Remove using namespace std
    da737f1 Add name input to hello_world
    8f224a5 Add hello_world.cpp with bad style
    70a9e11 Initial commit
  </details>

  ### Пункт 12 Удалите локальную ветку patch1.

```bash
git branch -d patch1
```
<details>
  <summary>Вывод</summary>

    Deleted branch patch1 (was 56cdb34).
  </details>

  ## Часть 3
### Пункт 1 Создайте новую локальную ветку patch2.
```bash
git checkout -b patch2
```
### Пункт 2 Измените code style с помощью утилиты clang-format. Например, используя опцию -style=Mozilla.
```bash
clang-format -style=Mozilla -i hello_world.cpp
```
Что поменялось в коде:
```bash
- int main() {
-     std::string name;
-     std::cout << "Enter your name: ";
+ int main()
+ {
+   std::string name;
+   std::cout << "Enter your name: ";
```
### Пункт 3 commit, push, создайте pull-request patch2 -> master.
```bash
git commit -am "Apply Mozilla code style"
```
<details>
  <summary>Вывод</summary>
  
      [patch2 066ec7e] Apply Mozilla code style
     1 file changed, 12 insertions(+), 12 deletions(-)
     rewrite hello_world.cpp (89%)
  </details>

```bash
git push origin patch2
```
<details>
  <summary>Вывод</summary>
  
      Username for 'https://github.com': Nicckki
    Password for 'https://Nicckki@github.com': 
    Enumerating objects: 109, done.
    Counting objects: 100% (109/109), done.
    Compressing objects: 100% (101/101), done.
    Writing objects: 100% (109/109), 33.08 KiB | 2.21 MiB/s, done.
    Total 109 (delta 54), reused 0 (delta 0), pack-reused 0
    remote: Resolving deltas: 100% (54/54), done.
    remote: 
    remote: Create a pull request for 'patch2' on GitHub by visiting:
    remote:      https://github.com/Nicckki/lab02/pull/new/patch2
    remote: 
    To https://github.com/Nicckki/lab02.git
     * [new branch]      patch2 -> patch2
  </details>
  Создаем pull-request patch1 -> main на GitHub через терминал.(как во второй части)
  
  ```bash
 hub pull-request -b main -h patch2 -m "Apply Mozilla code style"
  ```
В итоге высветилась ссылка на созданный pull request "https://github.com/Nicckki/lab02/pull/2"

### Пункт 4 В ветке master в удаленном репозитории измените комментарии, например, расставьте знаки препинания, переведите комментарии на другой язык.
Теперь нужно изменить файл hello_world.cpp прямо в ветке main на GitHub. Я решил сделать это прямо в GitHub, зашел в нужный репозиторий, открыд файл и поменял комментарии на английский язык, тем самым создав ***конфликт***

### Пункт 5 Убедитесь, что в pull-request появились конфликтны.
Открыл созданный Pull Request patch2 → main. GitHub показал красное сообщение: "This branch has conflicts that must be resolved" (Скриншоты прикреплять не буду, так как очень неудобно)

### Пункт 6 Для этого локально выполните pull + rebase (точную последовательность команд, следует узнать самостоятельно). Исправьте конфликты.
Разрешаем конфликт локально, для этого переключаемся на ветку patch2.

```bash
git checkout patch2
```
Стянем изменения из main (появятся конфликты).

```bash
git pull origin main
```
Выводит нам

```bash
 * branch            main       -> FETCH_HEAD
Auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
```
Открываем файл:

```bash
nano hello_world.cpp
```
Видим и исправляем:

```bash
<<<<<<< HEAD
#include <iostream>
#include <string>

int main()
{
  std::string name;
  std::cout << "Enter your name: ";
  std::cin >> name;
  std::cout << "Hello world from " << name << "!" << std::endl;
  return 0;
}
=======
#include <iostream>  // для ввода и вывода
#include <string>    // для работы со строками

// Главная функция программы
int main() {
    std::string name;  // имя пользователя
    std::cout << "Enter your name: ";  // запрос имени
    std::cin >> name;  // чтение имени
    std::cout << "Hello world from " << name << "!" << std::endl;  // приветствие
    return 0;  // успешное завершение
}
>>>>>>> 610eb63 (Update comments in hello_world.cpp)
```

```bash
#include <iostream>  // для ввода и вывода
#include <string>    // для работы со строками

// Главная функция программы
int main()
{
  std::string name;  // имя пользователя
  std::cout << "Enter your name: ";  // запрос имени
  std::cin >> name;  // чтение имени
  std::cout << "Hello world from " << name << "!" << std::endl;  // приветствие
  return 0;  // успешное завершение
}
```
Теперь сохраняем и добавляем полученный файл:

```bash
git add hello_world.cpp
```
Теперь базируем его:

```bash
git rebase --continue
```
Как видим, других конфликтов не возникло:

```bash
[detached HEAD 9ec4377] Apply Mozilla code style
 1 file changed, 13 insertions(+), 12 deletions(-)
 rewrite hello_world.cpp (98%)
Successfully rebased and updated refs/heads/patch2.
```

### Пункт 7 Сделайте force push в ветку patch2

```bash
git push origin patch2 --force
```
<details>
  <summary>Вывод</summary>
  
      Username for 'https://github.com': Nicckki
    Password for 'https://Nicckki@github.com': 
    Enumerating objects: 5, done.
    Counting objects: 100% (5/5), done.
    Compressing objects: 100% (3/3), done.
    Writing objects: 100% (3/3), 568 bytes | 568.00 KiB/s, done.
    Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
    remote: Resolving deltas: 100% (1/1), completed with 1 local object.
    To https://github.com/Nicckki/lab02.git
     + 066ec7e...9ec4377 patch2 -> patch2 (forced update)
  </details>

### Пункт 8 Убедитель, что в pull-request пропали конфликтны.
Откроем Pull Request на GitHub. Красное сообщение "Conflicts" исчезло и появилась зеленая кнопка "Merge pull request".

### Пункт 9 Вмержите pull-request patch2 -> master.
Сделали это на GitHub.(Также было принято решение удалить ветку patch2, как во 2 части, для большей наглядности)







