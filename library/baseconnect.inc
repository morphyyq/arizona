// Local database connection

print("NEW BASECONNECT LOADED");

mysql = mysql_connect("127.0.0.1", "samp", "samp123", "arizona");

if !mysql_errno(mysql) *then
    print("  [Data Base]: Connection established, loading continues!");
else
    printf("  [Data Base]: Connection error '%d', retrying connection.", mysql_errno(mysql));