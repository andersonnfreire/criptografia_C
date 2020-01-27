# Sistema de Criptografia em C


The messages sent are always in string format, that is, they consist of a
character vector. For simplification, only lowercase characters will be used,
digits and the symbols ‘,’ (comma) and ‘.’ (period).

The training law for the encryption of messages is as follows:
Pre-processing:
Eliminating corruption: every time the “corruption” substring is found, it
will be replaced by “”, that is, “corruption” is eliminated from the original string. That
technique should be applied to each of the substrings of the general string, if the substring
is different from “corruption” it is just copied.

Ex: “Never before in the history of this country has corruption been fought so much, but also
so many cases of corruption have never been found "=>" never before in the history of this country has so much been fought against, but so many cases of "have never been found".

# Parameters

- Implement the following functions:
  1) lerString that dynamically allocates a 5000 character string (use a #define SIZE 5000 constant) and promotes its reading through the keyboard, returning the informed string.
  2) eliminate Corruption that receives the informed string and returns a new pre-processed string.
  3) encryptedData which receives the informed string and returns a new string with the encrypted data.
  4) decryptsData that receives an encrypted string and recreates the original message by returning it.
  5) recreate Corruption that receives the pre-processed string and puts the “corruption” back in the original locations.

# Built With

Linguagem C.

# Authors

Anderson N. Freire - @andersonnfreire

# License

This project is licensed under the MIT License - see the LICENSE.md file for details.
