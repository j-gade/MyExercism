#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H

#include <string_view>

namespace rna_transcription {

char to_rna(char sequence);
std::string to_rna(std::string_view sequence);
    
}  // namespace rna_transcription

#endif // RNA_TRANSCRIPTION_H