<br />
<br />
<br />
<br />
<br /><br />

<pre dir='rtl'>




מודולרי א'<br>
<pre><code>Circle Arr[10]; // defined with default builder!<br>
<br>
Circle c1;<br>
Circle c1(3,3,9); // Error!<br>
<br>
Circle c1;<br>
C1.set(3,3,9) // OK!<br>
</code></pre>
הערות לדוגמא 6.12-14<br>
<br>
1.	הגדרת ערכי ברירת מחדל לארגומנטים רק בהצהרת המחלקה ולא במימוש.<br>
Time(int=0, int=0, int=0).<br>
2.	לא ניתן להוסיף להצהרות אלו בנאי ברירת מחדל (מפני שהבנאי שהוצהר כבר מכיל מצב ללא ארגומנטים) למעשה בנינו אאת שני הבנאים הבאים:<br>
time();<br>
time(int, int, int);<br>
3.<br>
<br>
<br>
<br>
<br>
<br>
</pre>