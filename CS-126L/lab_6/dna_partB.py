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

def calculate_mass_percentage( count_array, nucleotide_string ):
    junk_count = len(nucleotide_string) - sum(count_array)

    mass_A = count_array[0] * 135.128
    mass_C = count_array[1] * 111.103
    mass_G = count_array[2] * 151.128
    mass_T = count_array[3] * 125.107
    mass_junk = (junk_count * 100.000)

    total_mass = round(mass_A + mass_C + mass_G + mass_T + mass_junk, 1)

    per_A = round((mass_A / total_mass) * 100, 1)
    per_C = round((mass_C / total_mass) * 100, 1)
    per_G = round((mass_G / total_mass) * 100, 1)
    per_T = round((mass_T / total_mass) * 100, 1)

    return [per_A, per_C, per_G, per_T], total_mass


def get_codons( nucleotide_string ):
    codons_list = []
    temp_codon = ""
    for nucleotide_index in range(len(nucleotide_string)):
        nucleotide = nucleotide_string[nucleotide_index]
        if nucleotide != "-":
            temp_codon += nucleotide
            if len(temp_codon) == 3:
                codons_list.append(temp_codon)
                temp_codon = ""
    
    return codons_list

def is_protein( codons_list, nuc_count_list, total_mass ):
    c_and_g_mass = (nuc_count_list[1] + nuc_count_list[2] / total_mass) * 100
    if len(codons_list) >= 5 and codons_list[0] == "ATG" and codons_list[-1] in ["TAA", "TAG", "TGA"] and  c_and_g_mass > 30:
        return "YES"
    else:
        return "NO"

def main():
    user_file = input("Input file name? ")
    seq_name, seqs = read_dna_file(user_file)

    output_filename = input("Please input the name of the output file: ")
    with open(output_filename, "w") as output_file:

        for nucleotide_index in range(len(seqs)):
            nucleotide_string = seqs[nucleotide_index]
            nuc_count_list = count_nucleotides(nucleotide_string)
            mass_percent_list, total_mass = calculate_mass_percentage(nuc_count_list, nucleotide_string)
            codons_list = get_codons(nucleotide_string)
            nuc_is_protein = is_protein(codons_list, nuc_count_list, total_mass)
            output_file.write(f"Region Name: {seq_name[nucleotide_index]}\n")
            output_file.write(f"Nucleotides: {seqs[nucleotide_index]}\n")
            output_file.write(f"Nuc. Counts: {nuc_count_list}\n")
            output_file.write(f"Total Mass%: {mass_percent_list} of {total_mass}\n")
            output_file.write(f"Codons List: {codons_list}\n")
            output_file.write(f"Is Protein?: {nuc_is_protein}\n")
            output_file.write("\n")
    

main()