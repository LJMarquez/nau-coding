def read_dna_file( filename ):
    with open(filename) as data_stream:
        dna_data = data_stream.read()
    
    dna_data_list = dna_data.split("\n")
    seqs = []
    seq_name = []

    for item_index in range(1, len(dna_data_list) + 1):
        item = dna_data_list[item_index - 1]
        if item_index % 2 == 0:
            seqs.append(item.upper())
        else:
            seq_name.append(item)

    return seq_name, seqs

def count_nucleotides(sequence):
    a_count = 0
    c_count = 0
    g_count = 0
    t_count = 0
    for nucleotide_index in range(len(sequence)):
        nucleotide = sequence[nucleotide_index]
        if nucleotide == "A":
            a_count += 1
        elif nucleotide == "C":
            c_count += 1
        elif nucleotide == "G":
            g_count += 1
        elif nucleotide == "T":
            t_count += 1
    return [a_count, c_count, g_count, t_count]


def main():
    user_file = input("Input file name? ")
    print()
    seq_name, seqs = read_dna_file(user_file)

    for nucleotide_index in range(len(seqs)):
        nucleotide_string = seqs[nucleotide_index]
        nuc_count = count_nucleotides(nucleotide_string)
        print(f"Region Name: {seq_name[nucleotide_index]}")
        print(f"Nucleotides: {seqs[nucleotide_index]}")
        print(f"Nuc. Counts: {nuc_count}")
        print()

main()