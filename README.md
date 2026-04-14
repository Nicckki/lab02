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
