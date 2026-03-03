# compilers_8_sem_01_task
## Задание: 
1) Сделать свой форк от llvm репозитория
2) Создать свою ветку от llvmorg-20.1.0
3) Зарегистрировать таргет со своим названием (llc --version и clang -print-targets должны вывести его название)

## Инструкция по сборке и запуску:
  - сборка нового таргета:
```
	cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug -DLLVM_ENABLE_PROJECTS="clang" ../llvm-add-backend/llvm
    ninja llc clang
```
  - проверка регистрации таргета:
```
	bin/llc --version
```

## Скрин с проверкой регистрации нового таргета:
<img width="1016" height="1292" alt="Снимок экрана 2026-03-03 151501" src="https://github.com/user-attachments/assets/dd2b1097-5e1c-4989-98c3-7bf66331ccfb" />
