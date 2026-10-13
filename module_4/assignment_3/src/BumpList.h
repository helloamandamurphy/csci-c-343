#ifndef BUMPLIST_H
#define BUMPLIST_H


#include <optional>
#include <string>
#include "Sequence.h"

/**
 * Description: This class is modeled by (
 * left: string of T
 * right: string of T
 * )
 * exemplar self
 * @tparam T
 */

template<class T>
class BumpList

{
public:

    /**
     * Description: Constructor that initializes all attributes of this class.
     * replaces self
     * ensures: self = (<>,<>)
    **/
    BumpList();

    /**
     * Description:  Deconstructor that reclaims all space allocated.
    **/
    ~BumpList();

    /**
     *  Description: Clears all of the elements in the data structure
     *  clears self
    **/
    void clear();

    /**
     * Description: Transfer elements from one Bumplist to another
     * replaces self
     * clears source
     * ensures: self = \#source
     * @param source list to get elements from
     */
    void transferFrom(BumpList &source);

    /**
    *  Description: Assign Bumplist elements to self leaving rhs unchanged
    *  replaces self
    *  restores rhs
    *  ensures: self = rhs
    *  @param rhs Other sequence
    *  @return generic type Bumplist
    */
    BumpList<T> &operator=(BumpList const &rhs);

    /**
    *  Description: Moves to the start of the Bumplist.
    *  updates self
    *  ensures: self = (\<\>,\#self.left * \#self.right)
    */
    void moveToStart();

    /**
     *  Description: Moves to the end of the Bumplist.
     *  updates self
     *  ensures: self = (\#self.left * \#self.right,\<\>
    **/
    void moveToFinish();

    /**
     *  Description: Moves element to the left once.
     *  updates self
     * requires: self.right /= \<\>
     * ensures: self.left * self.right = \#self.left *
     * \#self.right and |self.left| = |\#self.left| + 1
    **/
    void advance();

    /**
    *  Description: Adds to the front right side of the BumpList.
    *  updates self.right
    *  clears x
    *  ensures: self = (\#self.left,<\#x> * \#self.right)
    *  @param x Generic type of element that is to be added to the front of right side of the Bumplist.
    **/
    void addRightFront(T &x);

    /**
     *  Description: Removes the element from the front rightside of the BumpList.
     *  updates self.right
     *  replaces x
     * requires: self.right /= \<\>
     * ensures: \<x\> is prefix of \#self.right and
     * self = (\#self.left,\#self.right[1,|\#self.right|))
     *  @param x Element to remove
    **/
    void removeRightFront(T &x);

    /**
    *  Description: Get the right side front value for the BumpList.
    *  restores self
    *  requires: self.right /= \<\>
    *  ensures: \<rightFront\> is prefix of self.right
    *  @return the front element of the right side of the BumpList.
    */
    std::optional<T> rightFront();

    /**
    *  Description: Replaces the front element on the right side of the BumpList.
    *  updates self.right, x
    * requires: self.right /= \<\>
    * ensures: \<x\> is prefix of \#self.right and
    * self = (\#self.left,\<\#x\> * \#self.right[1,|\#self.right|))
    * @param x element to replace the front value.
    */
    void replaceRightFront(T &x);

    /**
    *  Description: Swaps the right side of one Bumplist with another Bumplist.
    *  updates self.right, otherS.right
    *  ensures: self = (\#self.left,\#otherS.right) and
    *        otherS = (\#otherS.left,\#self.right)
    *  @param otherS the other Bumplist.
    */
    void swapRights(BumpList &otherS);

    /**
     *  Description: Finding the length of the left side of the BumpList.
     *  restores self
     *  ensures: leftLength = |self.left|
     * @return length of the left side of the BumpList.
     */
    int leftLength();

    /**
     *  Description: Finding the length of the right side of the BumpList.
     *  restores self
     *  ensures: rightLength = |self.right|
     * @return length of the right side of the BumpList.
     */
    int rightLength();

    /**
     * Finds the first occurrence of the value passed in.
     * @param elementToFind value to find in the BumpList
     * @return returns an optional int. Returns the location of the value starting from the left Sequence then going to the right Sequence.
     *          If the element is in the right queue, we return length of left queue plus location in right Sequence.
     */
    std::optional<int> find(T elementToFind);

    /**
    * Description: prints out values in the BumpList.
    * @return string containing values in BumpList
    */
    std::string outputBumpList();


private: // representation
    Sequence<T> right;
    Sequence<T> left;
    int size = 0;
};
#endif