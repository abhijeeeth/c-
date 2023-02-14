<?php
  session_start();

  // Connect to the database
  require_once "./functions/database_functions.php";
  $conn = db_connect();

  // Prepare and execute the SELECT query
  $query = "SELECT p.publisher_name, b.* FROM books b JOIN publisher p ON b.publisherid = p.publisherid GROUP BY p.publisher_name, b.book_isbn ORDER BY p.publisher_name";
  $result = mysqli_query($conn, $query);
  if (!$result) {
    echo "Can't retrieve data " . mysqli_error($conn);
    exit;
  }

  // Set the page title and include the header
  $title = "ERA Books";
  require_once "./template/header.php";

  // Print the page title
  echo "<h1 class='text-center text-muted'>Full Catalog of Books</h1>";
?>

<div class="container">
  <?php
    // Initialize the counter and the flag for starting a new row
    $count = 0;
    $new_row = true;
    $current_publisher = "";

    // Loop through the results and print the data
    while ($row = mysqli_fetch_assoc($result)) {
      // If it's a new publisher, print the publisher name and start a new row
      if ($current_publisher != $row['publisher_name']) {
        $current_publisher = $row['publisher_name'];
        if (!$new_row) {
          echo "</div>";
        }
        echo "<div class='row' style='margin-bottom:50px;'>";
        echo "<h4 class='col-12'>$current_publisher</h4>";
        $new_row = false;
      }

      // Print the book details
      echo "<div class='col-md-3 col-lg-2' style='margin-bottom:40px;'>
              <a href='book.php?bookisbn={$row['book_isbn']}'>
                <img class='img-responsive img-thumbnail' style='overflow:hidden; max-height:200px;' src='./bootstrap/img/{$row['book_image']}'>
                <p>{$row['book_title']}</p>
                <p>Price=$ {$row['book_price']}</p>
              </a>
            </div>";

      // Increment the counter and check if it's time to start a new row
      // $count++;
      // if ($count >= 7) {
      //   $count = 0;
      //   $new_row = true;
      // }
    }

    // Close the div element if needed
    if (!$new_row) {
      echo "</div>";
    }
  ?>
</div>

<?php
  // Close the MySQL connection and include the footer
  if (isset($conn)) { 
    mysqli_close($conn); 
  }
  require_once "./template/footer.php";
?>

