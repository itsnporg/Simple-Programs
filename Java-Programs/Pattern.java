package com.sujalsamai.Pattern;

import java.util.Scanner;

public class Pattern {
        public static void main(String[] args) {
            Scanner sc= new Scanner(System.in);
            System.out.print("Enter the number of rows: ");
            int n= sc.nextInt();
            rectangle(n);
            //can use any of the below functions in place of rectangle
        }

        static void rectangle(int n){
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print("* ");
                }
                System.out.println();
            }
        }

        static void rightTriangle(int n){
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    System.out.print("* ");
                }
                System.out.println();
            }
        }

        static void invertRightTraingle(int n){
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <=n-i+1 ; j++) {
                    System.out.print("* ");
                }
                System.out.println();
            }
        }

        static void numberRightTri(int n){
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= i; j++) {
                    System.out.print(j);
                }
                System.out.println();
            }
        }

        static void rotatedTri(int n){
            for (int i = 1; i <= 2*n; i++) {
                int totalcolumns= i>n? 2*n- i: i;
                for (int j = 1; j < totalcolumns; j++) {
                    System.out.print("* ");
                }
                System.out.println();
            }
        }

        static void mirroRightTri(int n){
            for (int i = 0; i < n; i++) {
                for (int j = 2*(n-i); j >=0; j--) {
                    System.out.print(" ");
                }
                for (int j = 0; j <=i ; j++) {
                    System.out.print("* ");
                }
                System.out.println();
            }
        }

        static void invertMirrorRight(int n){
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    System.out.print("  ");
                }
                for (int j = 1; j < n-i+1; j++) {
                    System.out.print("* ");
                }
                System.out.println();
            }
        }

        static void pyramid(int n){
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n-i; j++) {
                    System.out.print("  ");
                }
                for (int j = 1; j <=2*i-1; j++) {
                    System.out.print("* ");
                }
                System.out.println();
            }
        }

        static void invertPyramid(int n){
            for (int i = 1; i <=n; i++) {
                for (int j = 1; j <= i; j++) {
                    System.out.print("  ");
                }
                for (int j = 1; j <2*((n+1)-i) ; j++) {
                    System.out.print("* ");
                }
                System.out.println();
            }
        }

        static void triangle(int n){
            for (int i = 0; i <n; i++) {
                for (int j = n-i; j >1 ; j--) {
                    System.out.print(" ");
                }
                for (int j = 0; j <= i; j++) {
                    System.out.print("* ");
                }
                System.out.println();
            }
        }

        static void invertTriangle(int n){
            for (int i = 1; i <=n ; i++) {
                for (int j = 1; j <=i ; j++) {
                    System.out.print(" ");
                }
                for (int j = 1; j <=n-i+1 ; j++) {
                    System.out.print("* ");
                }
                System.out.println();
            }
        }

        static void hourglass(int n){
            for (int i = 1; i <=2*n ; i++) {
                if(i>n){
                    for (int j = 1; j <=n-(i-n) ; j++) {
                        System.out.print(" ");
                    }
                    for (int j = 1; j <= i-n; j++) {
                        System.out.print("* ");
                    }
                }else{
                    for (int j = 0; j <i ; j++) {
                        System.out.print(" ");
                    }
                    for (int j = 0; j <n-i+1 ; j++) {
                        System.out.print("* ");
                    }
                }
                System.out.println();
            }
        }

        static void hollowTraingle(int n) {
            for (int i = 1; i <= n; i++) // row=6
            {
                // Print spaces
                for (int j = i; j < n; j++) {
                    System.out.print("  ");
                }
                for (int k = 1; k < 2 * i; k++) {//print *
                    if (i == n || (k == 1 || k == 2 * i - 1))
                        System.out.print("* ");
                    else {
                        System.out.print("  ");
                    }
                }
                System.out.println();
            }
        }

        static void invertHollowTri(int n){
            for (int i = 1; i <=n ; i++) {
                for (int j = 1; j < i; j++) {
                    System.out.print("  ");
                }
                for (int k = 1; k<2*n  ; k++) {
                    if(i==1 || (k==1 || k==2*(n-i)+1)){
                        System.out.print("* ");
                    }else{
                        System.out.print("  ");
                    }
                }
                System.out.println();
            }
        }


        static void hollowDiamond(int n) {
            // for first half portion (top to bottom)
            for(int i=1; i <= n; i++) {
                for(int j = i; j <= n; j++) {
                    System.out.print(" ");
                }
                for(int k = 1; k <= 2*i-1; k++) {
                    if (k == 1 || k == (2 * i - 1))
                        System.out.print("*");
                    else
                        System.out.print(" ");
                }
                System.out.println();
            }
            // for second half portion
            for(int i=n-1; i >= 1; i--) {
                for(int j=n; j >= i; j--) {
                    System.out.print(" ");
                }
                for(int k=1; k <= 2*i-1; k++) {
                    if(k==1 || k==(2*i-1) )
                        System.out.print("*");
                    else
                        System.out.print(" ");
                }
                System.out.println();
            }
        }

        static void pascal(int n){
            for (int line = 1; line <=n ; line++) {
                for (int j = 0; j <=n-line ; j++) {
                    System.out.print(" ");
                }
                int el=1;
                for (int i = 1; i <=line ; i++) {
                    System.out.print(el+" ");
                    el=el*(line-i)/i;
                }
                System.out.println();
            }
        }

    }

