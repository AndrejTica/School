Backtracking: try and error: LABYRINTH: 
---------------------------------------------------------------------------
2 dim Array:	black	...wall			white	...not visited
				green	...visited way	red		...visited without exit
Entry:	left up: x=0, y=0
Exit:	right down: x= size, y= size
Call:	wayout(0,0)
Recursion:
	wayout(x,y)
		// END
		if wall		return -1
		if red		return -1 	// i was already here 
		if green	return -1 	// i was already here
		if exit		return 1	// DONE

		// TRY and ERROR
		// search a way
		mark green
		if wayout(oben)		return 1
		if wayout(rechts)	return 1
		if wayout(unten) 	return 1
		if wayout(links) 	return 1

		// ERROR: no way found
		mark red
		return -1

Backtracking: try and error: QUEEN 
---------------------------------------------------------------------------
chess-board:	2 dim Array (int)
				0	...	white		1	...	black		2	...	queen
Call: backtrack(0) // zeile 0
Recursion:
	backtrack(row)
		FOR all cols (col: 0...7)
			IF inDanger(row,col)								// TRY col
				CONTINUE TRY_NEXT_COL

			// set queen and TRY NEXT ROW
			IF NOT inDanger(row,col)
				SET queen AT chess[row][col]

				// lastROW? -> DONE -> END of RECURSION
				IF row==lastROW 			
					return TRUE;				
				ELSE
					// TRY_NEXT_ROW								// TRY row
					TRY_next_row= backtrack(row+1)

					IF TRY_next_row==TRUE 
						return TRUE
					ELSE
						// error						// ERROR->BACKTRACK
						// could not find any col for row+1
						UNSET queen AT chess[row][col]
						CONTINUE TRY_next_col					// TRY col

		END_FOR
		
		// ERROR: all cols tested
		return FALSE
