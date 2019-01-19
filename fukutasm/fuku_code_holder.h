#pragma once

#pragma pack(push, 1)

struct fuku_code_association {
    uint64_t original_virtual_address;
    uint64_t virtual_address;
};

struct fuku_code_label {
    uint8_t has_linked_instruction;
    
    union {
        uint64_t dst_address;
        fuku_instruction * instruction;
    };
};

struct fuku_image_relocation {
    uint32_t relocation_id;
    uint64_t virtual_address;
};

struct fuku_code_relocation {
    uint32_t relocation_id;
    uint8_t  offset;
    size_t label_idx;
};

struct fuku_code_rip_relocation {
    uint8_t  offset;
    size_t label_idx;
};

#pragma pack(pop)

class fuku_code_holder {
    fuku_assambler_arch arch;

    std::vector<fuku_code_label> labels;
    std::vector<fuku_code_relocation> relocations;
    std::vector<fuku_code_rip_relocation> rip_relocations;

    std::vector<size_t> available_relocations;
    std::vector<size_t> available_rip_relocations;


    std::vector<fuku_instruction *> original_lines; //sorted instructions with valid source_virtual_address

    linestorage  lines;

    bool merge_labels();
public:
    fuku_code_holder();
    fuku_code_holder(fuku_assambler_arch arch);
    fuku_code_holder(const fuku_code_holder& code_holder);
    ~fuku_code_holder();


    fuku_code_holder& operator=(const fuku_code_holder& code_holder);

    bool merge_code(const fuku_code_holder& code_holder);
public:
    void   update_virtual_address(uint64_t destination_virtual_address);
    void   update_origin_idxs();

    size_t create_label(fuku_instruction* line);
    size_t create_label(uint64_t dst_address);
    size_t create_relocation(uint8_t offset, uint64_t dst_address, uint32_t relocation_id);
    size_t create_relocation(uint8_t offset, fuku_instruction* line, uint32_t relocation_id);
    size_t create_relocation_lb(uint8_t offset, size_t label_idx, uint32_t relocation_id);
    size_t create_relocation(const fuku_code_relocation& reloc);
    size_t create_rip_relocation(uint8_t offset, uint64_t dst_address);
    size_t create_rip_relocation(uint8_t offset, fuku_instruction* line);
    size_t create_rip_relocation_lb(uint8_t offset, size_t label_idx);
    size_t create_rip_relocation(const fuku_code_rip_relocation& rip_reloc);

    void   delete_relocation(size_t idx);
    void   delete_rip_relocation(size_t idx);


    fuku_instruction& add_line();

    void clear();

    fuku_instruction * get_range_line_by_source_va(uint64_t virtual_address);
    fuku_instruction * get_direct_line_by_source_va(uint64_t virtual_address);

public:
    void set_arch(fuku_assambler_arch arch);

    void set_labels(const std::vector<fuku_code_label>& labels);
    void set_relocations(const std::vector<fuku_code_relocation>& relocs);
    void set_rip_relocations(const std::vector<fuku_code_rip_relocation>& rip_relocs);

    void set_available_relocations(const std::vector<size_t>& relocs);
    void set_available_rip_relocations(const std::vector<size_t>& rip_relocs);

    void set_original_lines_idxs(const std::vector<fuku_instruction *>& original_lines);

    void set_lines(const linestorage& lines);
public:
    std::vector<fuku_code_label>& get_labels();
    std::vector<fuku_code_relocation>& get_relocations();
    std::vector<fuku_code_rip_relocation>& get_rip_relocations();

    std::vector<size_t>& get_available_relocations();
    std::vector<size_t>& get_available_rip_relocations();

    std::vector<fuku_instruction *>& get_original_lines();

    linestorage&  get_lines();
public:
    fuku_assambler_arch get_arch() const;
    size_t get_labels_count() const;

    const std::vector<fuku_code_label>& get_labels() const;
    const std::vector<fuku_code_relocation>& get_relocations() const;
    const std::vector<fuku_code_rip_relocation>& get_rip_relocations() const;

    const std::vector<size_t>& get_available_relocations() const;
    const std::vector<size_t>& get_available_rip_relocations() const;

    const std::vector<fuku_instruction *>& get_original_lines() const;

    const linestorage&  get_lines() const;
};

std::vector<uint8_t> finalize_code(fuku_code_holder&  code_holder, 
    std::vector<fuku_code_association>* associations,
    std::vector<fuku_image_relocation>* relocations);