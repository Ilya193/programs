package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void onClickSolve(View view)
    {
        TextView tv_ = (TextView) findViewById(R.id.textView);
        EditText et = (EditText) findViewById(R.id.editTextTextPersonName3);
        String beg = et.getText().toString();
        String end = "";

        //все знаки и числа в уравнении
        char sign1 = ' ', sign2 = ' ', sign3 = ' ';
        double num1 = 0.0, num2 = 0.0, num3 = 0.0, d = 0.0, root = 0.0, x1 = 0.0, x2 = 0.0,
                numerator = 0.0, denominator = 0.0;
        String irv_s = ""; // для чисел, чтобы конвертировать в double
        int z = 1;
        int count_sign = 0;

        for (int key = 0; key < beg.length(); key++)
        {
            String pr1 = " ";
            String pr2 = "=";

            if (beg.charAt(key) != '1' && beg.charAt(key) != '2' && beg.charAt(key) != '+'
                    && beg.charAt(key) != '3' && beg.charAt(key) != '4' && beg.charAt(key) != '5'
                    && beg.charAt(key) != '6' && beg.charAt(key) != '7' && beg.charAt(key) != '8'
                    && beg.charAt(key) != '9' && beg.charAt(key) != '0'
                    && beg.charAt(key) !=  '-' && beg.charAt(key) != '=')
            {
                z = 0;
            }

            if (beg.charAt(key) == '-' || beg.charAt(key) == '+')
            {
                count_sign++;
            }

            if (beg.charAt(key) == pr1.charAt(0))
            {
                continue;
            }

            if (beg.charAt(key) == pr2.charAt(0))
            {
                break;
            }

            if (beg.charAt(0) == '-' && key == 0)
            {
                sign1 = beg.charAt(key);
                continue;
            }

            if (beg.charAt(0) == '+' && key == 0)
                continue;

            char ch = beg.charAt(key);
            end = end + ch;
        }

        if (count_sign > 3 || count_sign < 2)
            z = 0;

        if (z == 1)
        {
            for (int i = 0; i < end.length(); i++)
            {
                if (end.charAt(i) != '-' && end.charAt(i) != '+')
                {
                    irv_s += end.charAt(i);
                }
                else
                {
                    num1 = Double.valueOf(irv_s);
                    sign2 = end.charAt(i);
                    irv_s = "";

                    for (int x = i + 1; x < end.length(); x++)
                    {
                        if (end.charAt(x) != '-' && end.charAt(x) != '+')
                        {
                            irv_s += end.charAt(x);
                        }
                        else
                        {
                            num2 = Double.valueOf(irv_s);
                            irv_s = "";
                            sign3 = end.charAt(x);
                            for (int j = x + 1; j < end.length(); j++)
                            {
                                irv_s += end.charAt(j);
                            }
                            num3 = Double.valueOf(irv_s);

                            break;
                        }
                    }

                    break;
                }
            }

            if (sign1 == '-')
            {
                num1 *= -1;
            }
            if (sign2 == '-')
            {
                num2 *= -1;
            }
            if (sign3 == '-')
            {
                num3 *= -1;
            }

            if (sign1 == '-')
            {
                num1 *= -1;
                num2 *= -1;
                num3 *= -1;

                d = (num2 * num2) - 4 * num1 * num3;
                root = Math.sqrt(d);

                TextView d_gui = (TextView) findViewById(R.id.textView2);
                TextView x1_gui = (TextView) findViewById(R.id.textView8);
                TextView x2_gui = (TextView) findViewById(R.id.textView9);

                if (d > 0)
                {
                    d_gui.setText("D = " + String.valueOf(num2 * num2) + " - " + String.valueOf(4 *
                            num1 * num3) + " = " + String.valueOf(d) + ", " + String.valueOf(root) + "²");
                    numerator = -num2 + root;
                    denominator = 2 * num1;
                    x1 = numerator / denominator;
                    x1_gui.setText("x1 = " +  String.valueOf(numerator) + " / " + String.valueOf(denominator)
                            + " = " + String.valueOf(x1));

                    numerator = -num2 - root;
                    x2 = numerator / denominator;
                    x2_gui.setText("x2 = " +  String.valueOf(numerator) + " / " + String.valueOf(denominator)
                            + " = " + String.valueOf(x2));
                }
                if (d == 0)
                {
                    d_gui.setText("D = " + String.valueOf(num2 * num2) + " - " + String.valueOf(4 *
                            num1 * num3) + " = " + String.valueOf(d) + ", " + String.valueOf(root) + "²");
                    numerator = -num2 + root;
                    denominator = 2 * num1;
                    x1 = numerator / denominator;
                    x1_gui.setText("x1 = " +  String.valueOf(numerator) + " / " + String.valueOf(denominator)
                            + " = " + String.valueOf(x1));
                    x2_gui.setText("");
                }
                if (d < 0)
                {
                    d_gui.setText("D = " + String.valueOf(num2 * num2) + " - " + String.valueOf(4 *
                            num1 * num3) + " = " + String.valueOf(d));
                    Toast toast = Toast.makeText(this, "D < 0", Toast.LENGTH_LONG);
                    toast.show();
                }
            }
            else
            {
                d = (num2 * num2) - 4 * num1 * num3;
                root = Math.sqrt(d);
                TextView d_gui = (TextView) findViewById(R.id.textView2);
                TextView x1_gui = (TextView) findViewById(R.id.textView8);
                TextView x2_gui = (TextView) findViewById(R.id.textView9);

                if (d > 0)
                {
                    d_gui.setText("D = " + String.valueOf(num2 * num2) + " - " + String.valueOf(4 *
                            num1 * num3) + " = " + String.valueOf(d) + ", " + String.valueOf(root) + "²");
                    numerator = -num2 + root;
                    denominator = 2 * num1;
                    x1 = numerator / denominator;
                    x1_gui.setText("x1 = " +  String.valueOf(numerator) + " / " + String.valueOf(denominator)
                            + " = " + String.valueOf(x1));

                    numerator = -num2 - root;
                    x2 = numerator / denominator;
                    x2_gui.setText("x2 = " +  String.valueOf(numerator) + " / " + String.valueOf(denominator)
                            + " = " + String.valueOf(x2));
                }
                if (d == 0)
                {
                    d_gui.setText("D = " + String.valueOf(num2 * num2) + " - " + String.valueOf(4 *
                            num1 * num3) + " = " + String.valueOf(d) + ", " + String.valueOf(root) + "²");
                    numerator = -num2 + root;
                    denominator = 2 * num1;
                    x1 = numerator / denominator;
                    x1_gui.setText("x1 = " +  String.valueOf(numerator) + " / " + String.valueOf(denominator)
                            + " = " + String.valueOf(x1));
                    x2_gui.setText("");
                }
                if (d < 0)
                {
                    d_gui.setText("D = " + String.valueOf(num2 * num2) + " - " + String.valueOf(4 *
                            num1 * num3) + " = " + String.valueOf(d));
                    Toast toast = Toast.makeText(this, "D < 0", Toast.LENGTH_LONG);
                    toast.show();
                }
            }
        }
        else
        {
            Toast toast = Toast.makeText(this, "некорректное выражение", Toast.LENGTH_LONG);
            toast.show();
        }
    }
}
