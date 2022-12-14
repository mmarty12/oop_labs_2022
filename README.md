# oop_labs_2022
Labs for oop course.

**Description:**
1. Два вікна діалогу. Спочатку з’являється перше, яке має дві кнопки: [Далі >] і [Відміна]. Якщо натиснути кнопку [Далі >], то воно закриється і з’явиться друге длг вікно, яке має кнопки: [< Назад], [Так] і [Відміна]. Якщо натиснути кнопку [< Назад], вікно закриється і перехід до першого вікна. Вікно діалогу з елементом списку (List Box) та двома кнопками: [Так] і [Відміна]. У список автоматично записуються назви груп нашого факультету. Якщо вибрати потрібний рядок списку і натиснути [Так], то у головному вікні повинен відображатися текст вибраного рядка списку.
---
2. Запрограмувати простий графічний редактор в об’єктно-орієнтованому стилі.
- статичний масив для Shape (14 mod 3 = 2) обсягом 114 об’єктів
- "гумовий" слід (14 mod 4 = 2) – суцільна лінія синього кольору
- прямокутник:
  - ввід по двом протилежним кутам для студентів, у яких (14 mod 2 = 0)
  - відображення: чорний контур прямокутника без заповнення для (14 mod 5 = 4)
- еліпс:
  - ввід від центру до одного з кутів охоплюючого прямокутника для (14 mod 2 = 0)
  - відображення: чорний контур з кольоровим заповненням для (14 mod 5 = 4)
  - колір заповнення: світло-зелений для (14 mod 6 = 2)
- позначка поточного типу об’єкту: в меню (метод OnInitMenuPopup) для студентів (14 mod
2 = 0)
---
3. Запрограмувати графічний інтерфейс користувача на базі лабораторної роботи №2.
- динамічний масив для Shape (15 mod 3 = 0) обсягом 114 об’єктів  
- "гумовий" слід (15 mod 4 = 3) – пунктирна лінія чорного кольору  
- прямокутник:  
  - ввід від центру до одного з кутів (15 mod 2 = 1) 
  - відображення: чорний контур з білим заповненням (15 mod 5 = 0)  
- еліпс: 
  - ввід по двом протилежним кутам охоплюючого прямокутника для (15 mod 2 = 1)  
  - відображення: чорний контур без заповнення (15 mod 5 = 0) 
- позначка поточного типу об’єкту: в заголовку вікна для (15 mod 2 = 1)
---
4. Запрограмувати графічний інтерфейс користувача, узагальнивши спосіб додавання нових фігур. 
- запрограмувати динамічний обєкт класу MyEditor, забезпечивши коректне його створення та знищення.
- усі кольори та стилі (за винятком "гумового" сліду) геометричних форм – як у лаб. роботі №3. "Гумовий" слід усіх фігур малювати пунктирною лінією викликом відповідної функції-члена класів Shape. Можливо (але не обов’язково) для малювання гумового сліду-контуру внести додаткову функцію у класи Shape.
- окрім чотирьох типів форм, які були у попередніх лаб. №2 та 3, запрограмувати ще введення та відображення двох нових фігур – лінія з кружочками та каркас куба. Кольори ліній та заповнення цих нових фігур студент визначає на свій смак. Відповідні класи цих фігур запрограмувати саме множинним успадкуванням.
- для усіх шести типів форм зробити кнопки Toolbar з підказками
- не створювати ієрархію класів-редакторів для вводу об'єктів різних форм (як було у попередніх лаб. №2, 3)
---
5.  Запрограмувати немодальне вікно таблиці, що відображає намальовані у головному вікні фігури. 
- запрограмувати об’єкт класу MyEditor на основі класичної реалізації Singleton.
- усі кольори та стилі геометричних форм – як у попередній лаб. роботі №4.
- для відкриття та закриття вікна таблиці передбачити окремий пункт меню. Воно повинно автоматично закриватися при виході з програми.
- таблиця повинна бути запрограмована як клас у окремому модулі. Інтерфейс модуля у вигляді оголошення класу таблиці.
- запрограмувати запис файлу множини об’єктів, що вводяться.

  **Додаткові завдання :**
- у вікні таблиці передбачено, щоб користувач міг виділити курсором рядок таблиці і відповідний об’єкт буде виділятися на зображенні у головному вікні.
- у вікні таблиці користувач може виділити курсором рядок таблиці і відповідний об’єкт буде вилучено з масиву об’єктів.
---
6. Створити три незалежні програми-проекти в одному рішенні. Головний проект – програма Lab6 має бути менеджером, який керує двома іншими програмами – Object2 та Object3. Програма Lab6 повинна автоматично, без участі користувача налагоджувати співпрацю та виконувати обмін повідомленнями з програмами Object2 та Object3 для виконання потрібного завдання згідно наведеному вище алгоритму. У кожній програмі передбачити автоматичну обробку потрібних повідомлень і переходів з одного стану в інший.
  
   **Програмa Lab6 :** 
- користувач вводить значення n, Min, Max у діалоговому вікні.
- програма викликає програми Object2, 3 і виконує обмін повідомленнями з ними для передавання, отримання інформації.

  **Програма Object2 :**
- створює матрицю n×n цілих (int) чисел у діапазоні Min – Max.
- показує числові значення у власному головному вікні.
- записує дані в Clipboard Windows у текстовому форматі.

  **Програма Object3 :**
- зчитує дані з Clipboard Windows.
- відображає значення детермінанту матриці у власному головному вікні.

