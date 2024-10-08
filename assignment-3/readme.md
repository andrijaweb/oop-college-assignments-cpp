# Пројектовати следећи скуп класа на програмском језику C++:

- Датум садржи месец и годину. И месец и година се могу дохватити. Може се проверити да ли су два датума једнака (оператор == или различита (оператор !=). Може да се упише на главном излазу у облику у облику месец/година (оператор <<).

- Апстрактна карта садржи целобројни јединствени аутоматски генерисани идентификатор. Може да јој се провери исправност на основу задате цене и датума. Треба онемогућити копирање. Може се приказати на главном изалзу (оператор <<).

- Месечна карта има задато име власника (низ карактера), годину и месец важења. Важење може да се продужи за задати месец и годину. Месечна карта је исправна ако је важећа задатог датума. Може се приказати на главном излазу (оператор <<) у облику име власника (карта) датум.

- Дневна карта има уплаћен износ (реалан број), подразумевано 50. Износ на карти може да се допуни задатим износом. Дневна карта је исправна ако је износ на њој већи од цене вожње задате приликом провере. Тада се износ на карти умањује за задату цену. Може се приказати на главном излазу (оператор <<) у формату износ(карта).

- Валидатор садржи низ од неколико карата (подразумевано 20). Може да се дода једна карта (оператор +=) и да се провери ваљаност свих карата у садржаном низу задавањем цене карте и датума. Провера се врши тако што се свака карта проверава а затим на главном излазу испише у засебном реду за сваку карту карта/исправност, где исправност може да има вредност важи/не важи. Валидатор се може копирати.

#### Написати програм који створи један валидатор и у њега дода неколико карата, а затим изврши проверу. Користити хардкодоване вредности – не треба учитавати са главног улаза. Све класе опремити потребним конструкторима и деструкторима за безбедно руковање меморијом.