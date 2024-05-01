
#include <absl/flags/flag.h>
#include <absl/flags/parse.h>
#include <absl/flags/usage.h>
#include <absl/log/initialize.h>
#include <absl/log/log.h>
#include <absl/strings/str_format.h>

#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

int main(int argc, char *argv[]) {
  absl::SetProgramUsageMessage("Written by Jose Fernando Lopez Fernandez.");
  std::vector<char *> positional_args = absl::ParseCommandLine(argc, argv);
  absl::InitializeLog();
  // Remove the program name from the list of positional arguments returned by
  // the command line parser.
  positional_args.erase(std::begin(positional_args));
  // Make sure there is at least one filename in the positional arguments
  // vector. There's nothing for us to do otherwise, so if no filename was
  // specified, we simply return with an error status.
  if (positional_args.size() < 1) {
    LOG(ERROR) << "No filename(s) provided.";
    return EXIT_FAILURE;
  }
  // Process the input files.
  for (const auto &filename : positional_args) {
    LOG(INFO) << absl::StrFormat("Processing file: %s", filename);
    std::fstream input_file;
    input_file.open(filename, std::ios::in);
    if (!input_file) {
      LOG(ERROR) << absl::StrFormat("Could not open file: %s", filename);
      // Since we weren't able to open the file, we obviously can't process it,
      // and we don't have any cleanup to take care of, so we can just go ahead
      // and move on to the next filename.
      continue;
    }
    // Make sure we do not skip over any whitespace in the input files. We want
    // to copy them verbatim to standard output.
    input_file.unsetf(std::ios_base::skipws);
    int8_t current_character = 0;
    while (true) {
      input_file >> current_character;
      if (input_file.eof()) {
        break;
      }
      std::cout << current_character;
    }
    input_file.close();
  }
  return EXIT_SUCCESS;
}
