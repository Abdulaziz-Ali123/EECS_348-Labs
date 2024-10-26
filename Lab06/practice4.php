<?php
// check for post
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $size = isset($_POST['size']) ? (int)$_POST['size'] : 0;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    echo "<table border='1'>";
    
    // generate row with column indexes
    echo "<tr><td></td>";
    for ($i = 1; $i <= $size; $i++) {
        echo "<td>$i</td>";
    }
    echo "</tr>";
    
    // generate table rows
    for ($i = 1; $i <= $size; $i++) {
        echo "<tr>";
        // row index index
        echo "<td>$i</td>";
        
        // calculate and display
        for ($j = 1; $j <= $size; $j++) {
            echo "<td>" . ($i * $j) . "</td>";
        }
        echo "</tr>";
    }
    echo "</table>";
}
?>