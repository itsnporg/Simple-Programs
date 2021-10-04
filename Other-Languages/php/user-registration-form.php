<html>
  <head>
  <title>Index</title>
  </head>
  <body>
  <h2 align="center">User Registration Form</h2>
  <form name="forml" method="post" action="UserRegistrationFormOutput.php" enctype="multipart/form-data">
    <table width="53%" border="0" align="center" cellpadding="5" cellspacing="0">
      <tr>
        <td width="49%">Name</td>
        <td colspan="2">
          <div align="left"
           <input type="text" name="name" size="25" maxlength="25">
         </div>
        </td>
      </tr>
      <tr>
        <td width="49%">&nbsp;</td>
        <td height="2" colspan="2">&nbsp;</td>
      </tr>
      <tr>
        <td width="49%" height="57">Address</td>
        <td height="57" colspan="2">
          <textarea name="address" cols="25" rows="4">  </textarea>
        </td>
      </tr>
      <tr>
        <td width="49%">&nbsp;</td>
        <td height="2" colspan="2">&nbsp;</td>
      </tr>
      <tr>
        <td width="49%"> Date of Birth</td>
        <td height="2" colspan="2">
          <select name=birth_month>
            <option selected value=1>January
            <option value=2> February
            <option value=3>March
            <option value=4>April
            <option value=5>May
            <option value=6>June
            <option value=7>July
            <option value=8>August
            <option value=9>September
            <option value=10>October
            <option value=11>November
            <option value=12>December 
      </select>
      <select name=birth_day>
            <option selected value=1>01
            <option value=2>02
            <option value=3>03
            <option value=4>04
            <option value=5>05
            <option value=6>06
            <option value=7>07
            <option value=8>08
            <option value=9>09
            <option value=10>10
            <option value=11>11
            <option value=12>12
            <option value=13>13
            <option value=14>14
            <option value=15>15
            <option value=16>16
            <option value=17>17
            <option value=18>18
            <option value=19>19
            <option value=20>20
            <option value=21>21
            <option value=22>22
            <option value=23>23
            <option value=24>24
            <option value=25>25
            <option value=26>26
            <option value=27>27
            <option value=28>28
            <option value=29>29
            <option value=30>30
            <option value=31>31</option>
          </select>
          <input maxlength=4 name=birth_year size=4>
             (Year)</td>
      </tr>
      <tr>
        <td width="49%" height="2">&nbsp;</td>
        <td height="2" width="17%">&nbsp;</td>
        <td height="2" width="34%">&nbsp;</td>
      </tr>
      <tr>
        <td width="49%">Gender</td>
        <td height="2" width="17%"><input type="radio" name="gender" value="M">Male </td>
        <td height="2" width="34%"><input type="radio" name="gender" value="F">Female </td>
      </tr>
      <tr>
        <td width="49%" height="5">&nbsp;</td>
        <td height="5" colspan="2">&nbsp;</td>
      </tr>
      <tr>
        <td width="49%">Music Preference </td>
        <td height="2" colspan="2">
          <table width="100%" border="0">
            <tr>
              <td>
                <input type="checkbox" name="pop" value="1">
                   Pop </td>
              <td>
                <input type="checkbox" name="rock" value="1">
                   Rock </td>
            </tr>
            <tr>
              <td>
                <input type="checkbox" name="jazz" value="1">
                   Jazz </td>
              <td>
                <input type="checkbox" name="metal" value="1">
                   Metal </td>
            </tr>
            <tr>
              <td>
                <input type="checkbox" name="instrumental" value="1">
                   Instrumental </td>
              <td>&nbsp;</td>
            </tr>
          </table>
        </td>
      </tr>
      <tr>
        <td width="49%" height="2">&nbsp;</td>
        <td colspan="2" height="2">&nbsp;</td>
      </tr>

      <tr>
        <td colspan="3">
          <div align="center">
            <input type="submit" name="Submit" value="Submit">
          </div>
        </td>
      </tr>
    </table>
  </form>
  </body>
  </html>
  
  
<!--   UserRegistrationFormOutput.php
  
<html>
  <head>
  <title>Display Output </title>
  </head>
  <body>
  <h2> Dear
  <?php
     if ($gender=='M') {
       echo "Mr.";
     } elseif ($gender=='F') {
       echo "Ms.";
     }
     echo " ", $name;
     ?> ! You have entered the following information: </h2>
     <table border="1">
       <tr>
         <td>Address </td>
         <td>
           <?php echo $address; ?>
         </td>
       </tr>
       <tr>
         <td>Date of Birth </td>
         <td>
           <?php echo $birth_month, " ", $birth_day, " ", $birth_year; ?>
         </td>
       </tr>
       <tr>
         <td colspan=2>You prefer listening to:
  <?php
  if (!(empty($pop))) {
      if ($pop==1){ 
         echo " Pop ";      
      }
  }
  if (!(empty($jazz))) {
     if ($jazz==1) { 
         echo " Jazz ";      
     }
  }
  if (!(empty($rock))) {
     if ($rock==1){ 
         echo " Rock ";      
     }
  }
  if (!(empty($instrumental))) {
     if ($instrumental==1) { 
         echo " Instrumental ";
     }
  }
  if (!(empty($metal))) {
     if ($metal==1){ 
         echo " Metal ";     
     }
  }
?>
</td>
</tr>

  </table>
  </body>
  </html>  
-->  
