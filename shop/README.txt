/* Name    -->	 M.Hemanth Kumar
   Roll.NO -->	 201601032	*/
   
   functions used ------------------
   
   		  :	printingTree
   		  :	inserting
   		  :	swap
   		  :	filedel
   		  :	bdel
   		  :	Modify
   		  :	addstackindatabase
   		  :	Purchasing
   		  

/* function name = printingTree  */

		* This function prints "Item ID ", " Item Name ", " Price ", " Quantity ", "Offer ",   of all the nodes in the binary using Pre-Order method.
		
/* function name = inserting */

		* This function inserts 0 or 1 into a node "top" and returns it.
		* It is used to store a binary number of a number .
		* By using binary representation traversing to the required node in the tree becomes simpler.
		
/* function Name = swap */
	
		* Deletes the product having quantity 0 after it being purchased in the binary tree.
		* To delete product details if its quantity becomes ZERO.
		* This function swap's the last node of the binary tree with the node having Quantity 0.

/* Function Name = filedel */
		
		* Deleting in file
		* This functionv makes use of two files.
		* One file is opened in read mode ,the other in write mode.
		* Stores the line number of product to be deleted in variable delete_line.
		* The details of the product having quantity 0 after being purchased are stored in a 2-D array.
		* Writes all the content in one file to other except the line containing product to be deleted by make use of variable 			  delete_line.
		* Removes the old file and renames the new file with old file name.

/* Function Name = bdel */
	
		* Purpose of this function is to traverse to the last node in the tree using binary representation used above.
		* It makes use of binary representation to traverse to the last node.
		* Stores parent variable of last node in a temperary node.
		* And then calls Swap function.
		* If the last node is right of its parent it makes parent->right=NULL; similar version applies for left.

/* Function Name = Modify */

		* Decrements quantity of the product after it gets purchased by the user.
		* If the quantity becomes 0, it calls bdel and filedel functions to delete the fields.
		* Else if the quantity != 0, it calls  addstackindatabase function written in other task, to reduce quantity by 1.

/* Function Name = Purchasing */

		* Searches the tree for matching Id given by the user 
		* Asks the user for conformation to buy.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````


Name:G.Sri Krishna Karthik
Roll NO.201601027
<---------------------027assign12.c-------------readme text-------- >



           TASK:   CREATING DATA SET

Data Structure:Complete Binnary Tree



*Create a new node:-(createdataset)
		Scanning the input from the data.txt file.It takes each line of the file 
into a single string and creates a newnode from that.In the next iteration the string will
be replaced.Newnode with respective memory will be alloted and assigns values to it and returns. 

------------------------------------------------------------------------------------------------------------   	
         
*Inserting the nodes in the tree:-
                As we are using complete binary tree I make a counter to count the number of
 nodes and and convert that integer to binary values so that it can be inserted.When 1 comes 
 the pointer moves to right and when 0 comes it moves towards to left.

-------------------------------------------------------------------------------------------------------------  
  
*Login user:-
            This function takes the email id from the user andd checks whether(checkvalidemailid)
 email id is valid or not.Then it checks as the user is already registered or not in 
 (userdetails.txt).Then it takes password and checks for it.
 
-------------------------------------------------------------------------------------------------------------- 
 
*sign up user:-
            This function takes the emailid from the user and the it asks the user two passwords inorder to confirm.
 This information will be appended to the file userdetails.txt with space between userid and password.
Then it calls for login user.

---------------------------------------------------------------------------------------------------------------

*admin login:-
           There will be only one admin login for the and is not for user purpose.Ten it displays the options for search,modify,add item.
          
----------------------------------------------------------------------------------------------------------------           
           
*add item:-
           This function takes the product details from the admin and appends it too the database file.

-----------------------------------------------------------------------------------------------------------------

Reason for using complete binary tree:
          As we have different fields to search like itemid,itemname,price,etc it difficult to create a those many binary search trees.
So considering the space complexity and time use have choosen complete binary to be better. 

<-------------------------------------------------------------------------------------------------------------------->      
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''



g.venkata.charan
201611127,ECE.
modify():
		->this function takes input from the admin about the product id and the field he wants to modify.
		->if admin wants to modify price then it takes proID and new price and calls modifypriceintree and modifypriceindatabase functions.
		->if admin wants to modify quantity then it takes proID and new quantity and calls modifyquantityintree and modifyquantityindatabase functions.
		->if admin wants to modify offer then it takes proID and new offer and calls modifyofferintree and modifyofferindatabase functions.
		->if admin wants to add stack then it takes proID and stack and calls addstackintree and addstackindatabase functions.

modifypriceintree():		
		->this function modify price of a particular product based on id in tree. 

modifyofferintree():		
		->this function modify offer of a particular product based on id in tree. 

modifyquantityintree():		
		->this function modify quantity of a particular product based on id in tree. 

addstackintree():		
		->this function add stack of a particular product based on id in tree. 

modifypriceindatabase:
		->this function modify price of a particular product based on id in database.

modifyofferindatabase:
		->this function modify offer of a particular product based on id in database.

modifyquantityindatabase:
		->this function modify quantity of a particular product based on id in database.

addstackindatabase:
		->this function add stack of a particular product based on id in database.		

 medthod used to modify in tree:
 		->In this function the arguments are productID and field to modify.
		->I traverse along the tree using pre-order traversal upto the last node in the tree using recursion.
		->while treversing i check whether the productID present in that node is equal to the product id given by the admin.
		->if productID matches then i modifies the  particular feild of that product.
		->if productID doesn't matches then keep on traversing in the tree until i get that productID.
		->Thus items are add is added in tree. 
 

method used for modifying in the database:
		->In this function the arguments are database filename,productID,and new field.
		->At first opens the file in read mode and go through each line using fgets function which get each line into a character array. 	
		->Then i check whether given itemId matches with that line's itemID.
		->if matches then i copy the entire line into another string str() and also count the line where i found the line in database which is useful to delete the line.
		->Then i copy each word in the str() into another 2d-character array using atoi argument and modifies the feild in the particular  index of array'
		->for deleting the line i usually copy all lines in database file to another temporary file  except the line which i want to delete.
		->Then i delete the file of database using remove function.
		->Then i rename the temporary file as the previous name of database file using rename function.
		->now i open the database file in append mode and append the newly modified line to the file.
		->Thus the field is modified in database successfully.      
		

^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$





--------------------------------------------------------------------------------------------------------------------------------------------
<---roll no-201611137--->
<---m.vamsi krishna--->
<---DS ASSIGNMENT-12--> 					

-------------------------------------------------------Se@RcH!nG-----------------------------------------------------------------------------

--->The main function of this task is that user can easily find the item he want based on his wish..
--->The user can search any item based on id,name or anything that item have,and the function will display all the items of his wish.....

--------------------------------------------------------------------------------------------------------------------------------------------

--->FUNCTION-SEARCHBYTYPE... 
			--->which asks the user what he wants..for eg:mobiles,watches,powerbanks,earphones etc...

---------------------------------------------------------------------------------------------------------------------------------------------
		
--->FUNCTION-SEARCHBYITEMID...
			--->In this function the user enters any itemid he wants...
			--->Checks if the current node is null.
    			--->Traverse the left subtree by recursively calling the function.
    			--->Display the data part of the current node.
    			--->Traverse the right subtree by recursively calling the function.

--------------------------------------------------------------------------------------------------------------------------------------------  			

--->FUNCTION-SEARCHBYITEMNAME...			       
			--->The above process is repeated for this function...

--------------------------------------------------------------------------------------------------------------------------------------------

--->FUNCTION-SEARCHBYITEMPRICE...
			--->The above process is repeated for this function...

----------------------------------------------------------------------------------------------------------------------------------------		

--->searching based on quantity(i.e no.of items user wants)...
			--->The above process is repeated for this function...

----------------------------------------------------------------------------------------------------------------------------------------

--->searching based on offer...
			--->The above process is repeated for this function...

--------------------------------------------------------------------------------------------------------------------------------------------

--->FUNCTION-ISSUBSTRING...
			--->This function is useful  for example..if the user enters the item name as sam 
					then the functionn will find all the items having the substring sam...

-------------------------------------------------------------------------------------------------------------------------------------------

--->WHY I USED RECURSION...
			--->The main advantage of recursion is usually simplicity...
			--->though it may require large amounts of memory if the depth of the tree is very large but it is easy to understand.
				and it takes less effort...so,I preferred this...  
			--->High memory consumption is due to large function call number (recursion means that function calls itself multiple times).

--------------------------------------------------------------------------------------------------------------------------------------------

--->FUNCTION-CHANGINGITEMNAME...
			--->This function is useful when user wants to search based on item name...
			--->It converts the name given by user as the name in the database...so that there wil be no problem even if the 
				user gives capital letters in place of small or vice versa....
 
 -------------------------------------------------------------------------------------------------------------------------------------------




