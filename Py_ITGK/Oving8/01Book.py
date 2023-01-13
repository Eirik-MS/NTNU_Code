import matplotlib.pyplot as plt


def get_chapter(filename, chapter_delimiter):
    #Returns a list of strings, each string is a chapter
    #Chapter delimiter is a string that marks the start of a new chapter
    with open(filename, 'r') as f:
        chapters = f.read().split(chapter_delimiter)
        chapters.pop(0) #Remove the first empty string

    return chapters

def count_words(chapters, word):
    #Returns the number of times word appears in chapters
    counted_words = []
    for chapter in chapters:
        counted_words.append(chapter.count(word))
    print(counted_words)
    return counted_words

def create_numbers(number):
    #Returns a list of numbers from 1 to number
    numbers = []
    for i in range(1, number+1):
        numbers.append(i)
    return numbers

def analyze_word(filename, chapter_delimiter, word):
    #Returns a list of tuples, each tuple contains the chapter number and the number of times word appears in the chapter
    chapters = get_chapter(filename, chapter_delimiter)
    counted_words = count_words(chapters, word)
    index = create_numbers(len(chapters))

    plt.plot(index, counted_words, label=f'Number of times "{word}" appears in {filename}')
    plt.legend()
    plt.show()

    return 0

def analyze_words(filename, chapter_delimiter, words):
    #Returns a list of tuples, each tuple contains the chapter number and the number of times word appears in the chapter
    chapters = get_chapter(filename, chapter_delimiter)
    index = create_numbers(len(chapters))
    for word in words:
        counted_words = count_words(chapters, word)
        plt.plot(index, counted_words, label=f'Number of times "{word}" appears in {filename}')
    plt.legend()
    plt.show()

    return 0

if __name__ == '__main__':
    words = ["rabbit", "caterpillar", "sister", "cat", "queen", "turtle", "hatter"]
    analyze_words('alice_in_wonderland.txt', 'CHAPTER', words)
    
