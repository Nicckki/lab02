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
Здесь мы создаем конфигурационный файл для утилиты hub, в котором хранятся логин и токен для доступа к GitHub, а также глобально настраиваем Git на использование протокола "https".
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

