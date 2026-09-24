<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">По дисциплине “Общая теория интеллектуальных систем”</p>
<p align="center">Тема: “Моделирования температуры объекта”</p>
<br><br><br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 2 курса</p>
<p align="right">Группы ИИ-30</p>
<p align="right">Семенюк А. С.</p>
<p align="right">Проверил:</p>
<p align="right">Дворанинович Д. А.</p>
<br><br><br><br><br>
<p align="center">Брест 2026</p>




## Вариант 18

*   **Model 1.8 (Generalized Autoregressive Linear Model):**
    $$\Large y_{\tau+1} = a_1y_{\tau} + a_2y_{\tau-1} + b_1u_{\tau} + b_2u_{\tau-1}$$

*   **Model 2.2 (Actuator Saturation Non-linearity):**
    $$\Large y_{\tau+1} = ay_{\tau} + b \cdot \text{sat}(u_{\tau})$$

$$
\text{where } \text{sat}(u) = 
\begin{cases} 
U_{\max}, & u > U_{\max} \\ 
u, & U_{\min} \le u \le U_{\max} \\ 
U_{\min}, & u < U_{\min} 
\end{cases}
$$

*   **Model 3.6 (Cubic Growth and Control):**
    $$\Large \frac{dy}{dt} = ay^3 + bu$$
    <!--
    $$ \implies y_{\tau+1} = y_{\tau} + \Delta t (a y_{\tau}^3 + b u_{\tau})$$
    -->
    Метод Эйлера:
    $$\y = y + h*(a*y^3 + b*u)
