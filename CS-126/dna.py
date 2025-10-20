# Write a function named dna_errors that accepts two strings representing DNA sequences as parameters and returns an integer representing the number of errors found between the two sequences, using a formula described below. DNA contains nucleotides, which are represented by four different nucleotides A, C, T, and G. DNA is made up of a pair of nucleotide strands, where a nucleotide from the first strand is paired with a corresponding nucleotide from the second. The nucleotides are paired as follows:

# A is paired with T and vice-versa.
# C is paired with G and vice-versa.
# Below are two perfectly matched DNA strands. Notice how the nucleotides are paired up according to the above rules.

# "GCATGGATTAATATGAGACGACTAATAGGATAGTTACAACCCTTACGTCACCGCCTTGA"
#  ororororororororororororororororororororororororororororor|
# "CGTACCTAATTATACTCTGCTGATTATCCTATCAATGTTGGGAATGCAGTGGCGGAACT"
# In some cases, errors occur within DNA molecules the task of your function is to find two particular kinds of errors:

# Unmatched nucleotides, in which one strand contains a dash ('-') at a given index, or does not contain a nucleotide at the given index (if the strings are not the same length). Each of these counts as 1 error.
# Pomutations, in which a nucleotide from one strand is matched against the wrong nucleotide in the other strand. For example, A might accidentally pair with C, or G might pair with G. Each of these counts as 2 errors.
# For example, consider these two DNA strands:

# index 01234567890123456789012
#      "GGGA-GAATCTCTGGACT"
#      "CTCTACTTA-AGACCGGTACAGG"
# This pair of strands has three pomutations (at indexes 1, 15, and 17), and seven unmatched nucleotides (dashes at indexes 4 and 9, and nucleotides in the second string with no match at indexes 18-22). The pomutations count as a total of 3 * 2 = 6 errors, and the unmatched nucleotides count as 7 * 1 = 7 errors, so your function would return an error count of 6+7 = 13 total errors if passed the two above strands.

# You may assume that each string consists purely of the characters A, C, T, G, and - (the dash character), but the nucleotides could appear in either upper or lowercase. The strings might be the same length, or the first or second might be longer than the other. Either string could be very long, very short, or even the empty string. If the strings match perfectly with no errors as defined above, your function should return 0.

def dna_errors( strand1, strand2):
    error_count = 0
    short_strand = strand1
    new_strand = ""

    strand1_length = len(strand1)
    strand2_length = len(strand2)

    if strand1_length != strand2_length:
        if strand1_length > strand2_length:
            error_count += strand1_length - strand2_length
            short_strand = strand2
        else:
            error_count += strand2_length - strand1_length
   
    for nucleotide_index in range(len(short_strand)):
        if strand1[nucleotide_index] == "-":
            error_count += 1
        if strand2[nucleotide_index] == "-":
            error_count += 1

        nucleotide = strand1[nucleotide_index]

        if nucleotide == "A":
            new_strand += "T"
        elif nucleotide == "T":
            new_strand += "A"
        elif nucleotide == "G":
            new_strand += "C"
        elif nucleotide == "C":
            new_strand += "G"
        else:
            new_strand += nucleotide

        if new_strand[nucleotide_index] != "-" and strand2[nucleotide_index] != "-":
            if new_strand[nucleotide_index] != strand2[nucleotide_index]:
                error_count += 2
   
    return error_count

print(dna_errors("GCATGGATTAATATGAGACGACTAATA-GATAGTTACAACCCTTACGTCACCGCCTTGA", "CGTACCTAATTATACTCTGCTGATTATCCTATCAATGTTGGGAATGCAGTGGCGGAACT"))
