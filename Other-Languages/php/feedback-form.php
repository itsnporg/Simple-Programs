<HTML>
<HEAD>
<TITLE>All-In-One Feedback Form</TITLE>
</HEAD>
<BODY>
<?php
$form_block = "
  <FORM METHOD=\"POST\" ACTION=\"$PHP_SELF\">
    <P><strong>Your Name:</strong><br>
    <INPUT type=\"text\" NAME=\"sender_name\" SIZE=30></P>
    <P><strong>Your E-Mail Address:</strong><br>
    <INPUT type=\"text\" NAME=\"sender_email\" SIZE=30></P>
    <P><strong>Message:</strong><br>
    <TEXTAREA NAME=\"message\" COLS=30 ROWS=5 WRAP=virtual></TEXTAREA></P>
    <INPUT type=\"hidden\" name=\"op\" value=\"ds\">
    <P><INPUT TYPE=\"submit\" NAME=\"submit\" VALUE=\"Send This Form\"></p>
</FORM>";

if ($_POST[op] != "ds") {
     echo "$form_block";
} else if ($_POST[op] == "ds") {
     if ($_POST[sender_name] == "") {
          $name_err = "<font color=red>Please enter your name!</font><br>";
          $send = "no";
     }
     if ($_POST[sender_email] == "") {
          $email_err = "<font color=red>Please enter your
          e-mail address!</font><br>";
          $send = "no";
     }
     if ($_POST[message]== "") {
          $message_err = "<font color=red>Please enter a message!</font><br>";
          $send = "no";
     }
     if ($send != "no") {
          $msg = "E-MAIL SENT FROM java2s.com\n";
          $msg .= "Sender's Name: $_POST[sender_name]\n";
          $msg .= "Sender's E-Mail: $_POST[sender_email]\n";
          $msg .= "Message: $_POST[message]\n\n";
          $to = "you@yourdomain.com";
          $subject = "All-in-One Web Site Feedback";
          $mailheaders = "From: My Web Site
          <genericaddress@yourdomain.com>\n";
          $mailheaders .= "Reply-To: $_POST[sender_email]\n";
          mail($to, $subject, $msg, $mailheaders);
          echo "<P>Mail has been sent!</p>";
     } else if ($send == "no") {
          echo "$name_err";
          echo "$email_err";
          echo "$message_err";
          echo "$form_block";
     }
}
?>
