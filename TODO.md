# GroupProject_Customer_Accounts

<strong>I will have to take a break from this project for the next day or so. My java project is due Sunday and still needs quite a bit of work while our project isn't due until Wednesday the 27<small>th</small> </strong>

TODO list for the accountOperations class

1)add constructor to the class
the constructur will create a record file if one does not exist
<strong>See most recent push - Robert</strong>

2)write createRecord() 
the create record method will call all the setter methods and add the newly completed
struct to the record file
<strong>See most recent push - Robert</strong>

3)write displayAllRecords() 
this will display the entire record file <strong>done -Robert</strong>

4)write findRecord()
displays a single record <strong>done - Jem</strong>

5)write deleteRecord()
to delete a customer record <strong>done - Jem</strong>

6)write  changeRecord()
to edit a current record

Tasks 5&6 will be dependent on getRecord() as this will be called first 

7) Split the input for First and Last name.  If you input these incorrectly, the errors put out make it incoherent.  Get and check for one thing at a time.
<em>Jem: That shouldn't be a problem to split them up I don't see the being inchoherent part though, as I am not sure how to recreate the issue I have noticed a minor bug of being asked for address line 1 twice some times though I am not sure what causes it to occur. prior to making the split I want to focus on tasks 4-6 as these are the last major things</em>
<em><strong>Robert, I fixed the problem I think I had with the name, I think it was just that if you entered both names with a space on the first input, it left the last name in the buffer.  So, it would write fine, but it would be a bit confusing to the user.  This should also solve the address line 1 appearing twice sometimes, since that has to do with not emptying the buffer I think.  I completed 4, will work on the others tomorrow if I have time.
Also, do we really need to use \a?  I find those alert tones quite jolting/annoying for a simple input error.  That's just a personal preference though.</strong></em>

