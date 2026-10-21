## Clignotement d'une LED

Les lignes suivantes clignottent la led intégrée (builtin en anglais) à la carte:

```c
digitalWrite(LED_BUILTIN, HIGH); // 3.3V sur la broche led
delay(1000); // on attend 1s
digitalWrite(LED_BUILTIN, LOW); // 0V sur la broche led
delay(1000); // on attend 1s
```

