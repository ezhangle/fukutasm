#pragma once

#pragma pack(push, 1)

class fuku_instruction {
    uint16_t id; //instruction id

    uint8_t op_length;    //instruction size
    uint8_t	op_code[16];  //instruction
    
    //association
    uint64_t source_virtual_address;    //original va of instruction , == -1 if wasnt in original code
    uint64_t virtual_address;		    //resulted va of instruction 

    //relative idxs    if has index then value => 0 else -1
    size_t label_idx;

    size_t code_relocation_1_idx;
    size_t code_relocation_2_idx;
    size_t code_rip_relocation_idx;
			   
    uint32_t instruction_flags; //combination of fuku_instuction_flags

    uint64_t eflags;
    uint64_t custom_flags;

    uint8_t get_prefixes_number() const;
public:
    fuku_instruction();
    fuku_instruction(const fuku_instruction& line);
    ~fuku_instruction();

    fuku_instruction& operator=(const fuku_instruction& line);
public:
    fuku_instruction& set_id(uint16_t id);

    fuku_instruction&  set_op_code(const uint8_t* op_code, uint8_t lenght);

    fuku_instruction&  set_source_virtual_address(uint64_t va);
    fuku_instruction&  set_virtual_address(uint64_t va);

    fuku_instruction&  set_label_idx(size_t idx);

    fuku_instruction&  set_relocation_first_idx(size_t idx);
    fuku_instruction&  set_relocation_second_idx(size_t idx);
    
    fuku_instruction&  set_rip_relocation_idx(size_t idx);

    fuku_instruction&  set_instruction_flags(uint32_t instruction_flags);
    
    fuku_instruction&  set_eflags(uint64_t eflags);
    fuku_instruction&  set_custom_flags(uint64_t custom_flags);
public:
    uint16_t get_id() const;

    const uint8_t* get_op_code() const;
    uint8_t  get_op_length() const;
    uint8_t  get_op_pref_size() const;

    uint64_t get_source_virtual_address() const;
    uint64_t get_virtual_address() const;
    
    size_t get_label_idx() const;

    size_t get_relocation_first_idx() const;
    size_t get_relocation_second_idx() const;

    size_t get_rip_relocation_idx() const;

    uint32_t get_instruction_flags() const;
    uint64_t get_eflags() const;
    uint64_t get_custom_flags() const;
};

#pragma pack(pop)

typedef std::list<fuku_instruction> linestorage;