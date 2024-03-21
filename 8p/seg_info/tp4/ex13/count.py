def count_differences(str1, str2):
    """
    Count the number of differences between two strings.

    Args:
    - str1 (str): First string.
    - str2 (str): Second string.

    Returns:
    - int: Number of differences between the two strings.
    """
    # Ensure both strings have the same length
    if len(str1) != len(str2):
        raise ValueError("Both strings must have the same length.")

    # Initialize a counter for differences
    num_differences = 0

    # Iterate over each character in the strings
    for char1, char2 in zip(str1, str2):
        # Compare characters and increment counter if they differ
        if char1 != char2:
            num_differences += 1

    return num_differences


# Example usage:
str1 = "01001000 00100111 11111100 01001001 10110101 01110110 10000011 01011011 11010000 01001100 11011001 00010101 11000101 00011111 10011110 00000011"
str2 = "00011001 00101111 00000110 10100100 11110100 01010000 00111101 11010010 00101001 01001001 00111011 01111101 10111110 10110001 10011101 00010010"
print("Number of differences:", count_differences(str1, str2))
