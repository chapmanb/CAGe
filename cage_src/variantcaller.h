/**
 * Copyright 2015 Adam Bloniarz, Jonathan Terhorst, Ameet Talwalkar
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef CAGE_VARIANTCALLER_H
#define CAGE_VARIANTCALLER_H

#include <string>
#include <vector>
#include <map>
#include <tuple>
#include <memory>

namespace cage {

  class VariantCaller {
    public:
      VariantCaller(const int& length, const int& start_position, const std::string& full_ref, const std::string& contig);

      std::vector<std::tuple<int, int, int>> report_variants(const std::vector<int>& depth, const std::string& vcf_file);

      virtual void increment_mismatch(const int& pos, const std::string& alt_bases, const bool& reverse_strand);

    private:
      class alt_counts {
        public:
          int nf = 0;
          int nr = 0;
          alt_counts(int f, int r) : nf(f), nr(r) {}
      };

      typedef std::map<std::string, alt_counts> alt_map;

      int start_position;
      const std::string& full_ref;
      std::string contig;

      std::vector<std::unique_ptr<alt_map>> piles;
  };
}
#endif
