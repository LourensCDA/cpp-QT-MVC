# c++ QT MVC project for university

Not finished yet.

Use Qt’s model/view framework to store and display music CD information. The following
information should be stored in the model (a QStandardItemModel):

- composer,
- album name,
- cost, and
- a rating (out of 100).

The information should be displayed in a table.

The following functionality should be included.

- There should be a header row.
- The user should be able to add rows of data to the model.
- The user should be able to edit data in the view.
- The replacement value should always display the cents (even as .00), even after editing.
- The user should be able to sort the data by clicking on the column header on which the
  sorting should be implemented.
- Where the replacement value is greater than or equal to R250, the row should be made a
  different colour. Note that this colour should also change if the user edits a replacement
  value (and it should return to the normal colour if the value drops below R250).
- The user should be able to delete a row of data.
