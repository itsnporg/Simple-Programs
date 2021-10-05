import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.TextAlignment;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.shape.Rectangle;
import java.util.Objects;


public class Main extends Application{

    String str0 = "";
    String str1 = "";
    String str2 = "";
    public static void main(String[] args) {
        launch(args);
    }


    @Override
    public void start(Stage primaryStage) {

        GridPane gridPane = new GridPane();
        Scene HomeUI = new Scene(gridPane);

        Button btn0 = new Button("0");
        Button btn1 = new Button("1");
        Button btn2 = new Button("2");
        Button btn3 = new Button("3");
        Button btn4 = new Button("4");
        Button btn5 = new Button("5");
        Button btn6 = new Button("6");
        Button btn7 = new Button("7");
        Button btn8 = new Button("8");
        Button btn9 = new Button("9");
        Button btn00 = new Button("00");

        Button btnDot = new Button(".");
        Button btnPercent = new Button("%");
        Button btnDeleteAll = new Button("AC");
        Button btnAdd = new Button("+");
        Button btnSubtract = new Button("-");
        Button btnDevide = new Button("/");
        Button btnMultipy = new Button("x");
        Button btnEqual = new Button("=");

        Label data = new Label("");

        Rectangle r = new Rectangle();
        r.setFill(Color.DARKCYAN);
        r.setWidth(270);
        r.setHeight(150);
        r.setArcHeight(20);
        r.setArcWidth(20);
        gridPane.add(r,0,0,4,3);

        KlikBtn(btn0, data);
        KlikBtn(btn1, data);
        KlikBtn(btn2, data);
        KlikBtn(btn3, data);
        KlikBtn(btn4, data);
        KlikBtn(btn5, data);
        KlikBtn(btn6, data);
        KlikBtn(btn7, data);
        KlikBtn(btn8, data);
        KlikBtn(btn9, data);
        KlikBtn(btn00, data);
        KlikBtn(btnDot, data);
        KlikBtn(btnDevide, data);
        KlikBtn(btnMultipy, data);
        KlikBtn(btnEqual, data);
        KlikBtn(btnAdd, data);
        KlikBtn(btnSubtract, data);
        KlikBtn(btnDeleteAll, data);
        KlikBtn(btnPercent, data);




        ShowBtnOp2(gridPane, btnDeleteAll,0,4, 2,1);
        ShowBtnOp2(gridPane, btnPercent,2,4);

        ShowBtnOp(gridPane, btnDevide,3,4);
        ShowBtnOp(gridPane, btnMultipy,3,5);
        ShowBtnOp(gridPane, btnSubtract,3,6);
        ShowBtnOp(gridPane, btnAdd,3,7);
        ShowBtnOp(gridPane, btnEqual,3,8);

        ShowBtn(gridPane, btn7,0,5);
        ShowBtn(gridPane, btn8,1,5);
        ShowBtn(gridPane, btn9,2,5);

        ShowBtn(gridPane, btn4,0,6);
        ShowBtn(gridPane, btn5,1,6);
        ShowBtn(gridPane, btn6,2,6);

        ShowBtn(gridPane, btn1,0,7);
        ShowBtn(gridPane, btn2,1,7);
        ShowBtn(gridPane, btn3,2,7);
        ShowBtn(gridPane,btn0, 1,8);

        ShowBtn(gridPane,btn00, 0,8);
        ShowBtn(gridPane,btnDot, 2,8);

        data.setAlignment(Pos.CENTER_RIGHT);
        data.setTextAlignment(TextAlignment.RIGHT);
        data.setMaxWidth(260);
        gridPane.add(data,0,2,4,1);



        gridPane.setHgap(10);
        gridPane.setVgap(10);
        gridPane.setAlignment(Pos.CENTER);
        gridPane.setPadding(new Insets(30));
        gridPane.setBackground(new Background(new BackgroundFill(Color.rgb(40,44,53), CornerRadii.EMPTY, Insets.EMPTY)));
        HomeUI.getStylesheets().add(Objects.requireNonNull(getClass().getResource("style.css")).toExternalForm());

        primaryStage.setTitle("Kalkulator");
        primaryStage.setWidth(340);
        primaryStage.setHeight(600);
        primaryStage.setMinWidth(300);
        primaryStage.setMinHeight(600);
        primaryStage.setScene(HomeUI);
        primaryStage.show();
    }

    private void KlikBtn(Button btn, Label data) {
        btn.setOnMouseClicked(event -> {
            data.setText(btn.getText());
            String s = btn.getText();

            if ((s.charAt(0) >= '0' && s.charAt(0) <= '9') || s.charAt(0) == '.') {

                if (!str1.equals(""))

                    str2 = str2 + s;
                else
                    str0 = str0 + s;

                data.setText(str0 + str1 + str2);
            }
            else if(s.charAt(0) == '%'){
                if(!str0.equals("") && !str2.equals("")){
                    str2 = Double.toString((Double.parseDouble(str2) / 100));

                }else {
                    str0 = Double.toString((Double.parseDouble(str0) / 100));
                }
                data.setText(str0 + str1 + str2);
            }

            else if (s.equals("AC")) {

                str0 = str1 = str2 = "";

                data.setText(str0 + str1 + str2);
            }
            else if (s.charAt(0) == '=') {

                double hasil;


                if (str1.equals("+"))
                    hasil = (Double.parseDouble(str0) + Double.parseDouble(str2));
                else if (str1.equals("-"))
                    hasil = (Double.parseDouble(str0) - Double.parseDouble(str2));
                else if (str1.equals("/"))
                    hasil = (Double.parseDouble(str0) / Double.parseDouble(str2));
                else
                    hasil = (Double.parseDouble(str0) * Double.parseDouble(str2));

                data.setText(str0 + str1 + str2 + "=" + hasil);


                str0 = Double.toString(hasil);

                str1 = str2 = "";
            }
            else {

                if (str1.equals("") || str2.equals(""))
                    str1 = s;

                else {
                    double te;

                    if (str1.equals("+"))
                        te = (Double.parseDouble(str0) + Double.parseDouble(str2));
                    else if (str1.equals("-"))
                        te = (Double.parseDouble(str0) - Double.parseDouble(str2));
                    else if (str1.equals("/"))
                        te = (Double.parseDouble(str0) / Double.parseDouble(str2));
                    else
                        te = (Double.parseDouble(str0) * Double.parseDouble(str2));


                    str0 = Double.toString(te);

                    str1 = s;

                    str2 = "";
                }

                data.setText(str0 + str1 + str2);
            }
        });
    }


    private void ShowBtn(GridPane gridPane, Button btn, int kolom, int baris) {

        gridPane.add(btn,kolom,baris);
        btn.setStyle(" -fx-min-width: 60; -fx-min-height: 60; -fx-text-fill: #fff; -fx-font-size: 24; -fx-background-radius: 24");
    }
    private void ShowBtnOp(GridPane gridPane, Button btn, int kolom, int baris) {

        gridPane.add(btn,kolom,baris);
        btn.setStyle(" -fx-min-width: 60; -fx-min-height: 60; -fx-text-fill: #E87676; -fx-font-size: 22; -fx-background-radius: 24; -fx-font-weight: bold");
    }
    private void ShowBtnOp2(GridPane gridPane, Button btn, int kolom, int baris) {

        gridPane.add(btn,kolom,baris);
        btn.setStyle(" " +
                "" +
                " -fx-min-width: 60; -fx-min-height: 60;" +
                " -fx-text-fill: #26D4B6; -fx-font-size: 22; " +
                " -fx-background-radius: 24;" +
                " button-hover-color: #353A46 ;" +
                " ");



    }
    private void ShowBtnOp2(GridPane gridPane, Button btn, int kolom, int baris, int kolomspan, int barisspan) {

        gridPane.add(btn,kolom,baris, kolomspan, barisspan);
        btn.setStyle(" " +
                "" +
                " -fx-min-width: 120; -fx-min-height: 60;" +
                " -fx-text-fill: #26D4B6; -fx-font-size: 22; " +
                " -fx-background-radius: 24;" +
                " button-hover-color: #353A46 ;" +
                " ");



    }


}
