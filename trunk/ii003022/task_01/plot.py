import csv
import matplotlib.pyplot as plt

def to_float(s):
    return float(s.replace(",", "."))

t, u, y = [], [], []

with open("result.csv","r", encoding="utf-8") as file:
    reader = csv.reader(file, delimiter=";")
    next(reader)                       
    for row in reader:
        if not row:                   
            continue
        t.append(int(row[0]))
        u.append(to_float(row[1]))
        y.append(to_float(row[2]))

plt.figure(figsize=(8, 5))
plt.plot(t, y, "b-o", markersize=3, label="y(t) — выход модели")
plt.plot(t, u, "r--", label="u(t) — вход")
plt.xlabel("t (номер шага)")
plt.ylabel("значение")
plt.title("График моделирования, вариант 18")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("graph.png", dpi=150)     
plt.show()