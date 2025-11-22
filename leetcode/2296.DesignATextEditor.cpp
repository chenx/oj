// See https://algo.monster/liteproblems/2296

class TextEditor {
    string textBeforeCursor;
    string textAfterCursor;

public:
    TextEditor() {}
    
    void addText(string text) {
        textBeforeCursor += text;
    }
    
    int deleteText(int k) {
        int len = textBeforeCursor.length(), deleteLen = min(k, len);
        textBeforeCursor = textBeforeCursor.substr(0, len - deleteLen);
        return deleteLen;
    }
    
    string cursorLeft(int k) {
        int len = textBeforeCursor.length(), moveLen = min(k, len);

        textAfterCursor = textBeforeCursor.substr(len - moveLen) + textAfterCursor;
        textBeforeCursor = textBeforeCursor.substr(0, len - moveLen);

        int startIndex = max(0, (int) textBeforeCursor.length() - 10);
        return textBeforeCursor.substr(startIndex);
    }
    
    string cursorRight(int k) {
        int len = textAfterCursor.length(), moveLen = min(k, len);

        textBeforeCursor += textAfterCursor.substr(0, moveLen);
        textAfterCursor = textAfterCursor.substr(moveLen);

        int startIndex = max(0, (int) textBeforeCursor.length() - 10);
        return textBeforeCursor.substr(startIndex);
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */

/**
2296. Design a Text Editor
Hard

Design a text editor with a cursor that can do the following:

    Add text to where the cursor is.
    Delete text from where the cursor is (simulating the backspace key).
    Move the cursor either left or right.

When deleting text, only characters to the left of the cursor will be deleted. The cursor will also remain within 
the actual text and cannot be moved beyond it. More formally, we have that 0 <= cursor.position <= currentText.length 
always holds.

Implement the TextEditor class:

    TextEditor() Initializes the object with empty text.
    void addText(string text) Appends text to where the cursor is. The cursor ends to the right of text.
    int deleteText(int k) Deletes k characters to the left of the cursor. Returns the number of characters actually deleted.
    string cursorLeft(int k) Moves the cursor to the left k times. Returns the last min(10, len) characters to 
        the left of the cursor, where len is the number of characters to the left of the cursor.
    string cursorRight(int k) Moves the cursor to the right k times. Returns the last min(10, len) characters 
        to the left of the cursor, where len is the number of characters to the left of the cursor.

 

Example 1:

Input
["TextEditor", "addText", "deleteText", "addText", "cursorRight", "cursorLeft", "deleteText", "cursorLeft", "cursorRight"]
[[], ["leetcode"], [4], ["practice"], [3], [8], [10], [2], [6]]
Output
[null, null, 4, null, "etpractice", "leet", 4, "", "practi"]
 */
