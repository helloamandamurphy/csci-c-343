# Notes

## Change in tokenizing
Got feedback on Assignment 4 about improving tokenizing.

### Original numbers
- Words Found: 927260
- Words Not Found: 72281
- Total words: 999541
- Comparisons Found: 3009493274
- Comparisons Not Found: 512929131
- Average Comparisons Found: 3245.58
- Average Comparisons Not Found: 7096.32

I updated it to account for capitalization, and got these numbers:
### Capitalization Fix
- Words Found: 940250
- Words Not Found: 59291
- Total words: 999541
- Comparisons Found: 3345765642
- Comparisons Not Found: 468608624
- Average Comparisons Found: 3558.38
- Average Comparisons Not Found: 7903.54

Assignment 4 was splitting words with apostrophes from "I'll" -> "I" and "ll".
I changed that behavior to go from "I'll" to "ill", but this will have some overlap when contractions make other words (example: We'll -> well), so that's a trade off, but I made to to get closer to the example numbers in Assignment 4.

### Apostrophe Fix
- Words Found: 937545
- Words Not Found: 54685
- Total words: 992230
- Comparisons Found: 3336776366
- Comparisons Not Found: 403683304
- Average Comparisons Found: 3559.06
- Average Comparisons Not Found: 7381.98