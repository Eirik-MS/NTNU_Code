prime100 = 1522605027922533360535618378132637429718068114961380688657908494580122963258952897654000350692006139

def find_prime_in_range():    
    from tqdm import tqdm
    import concurrent.futures

    def is_prime(n):
        if n <= 1:
            return False

        for i in range(2, n):
            if n % i == 0:
                return False

        return True

    def find_primes(start, end):
        prime_numbers = []
        for num in range(start, end + 1):
            if is_prime(num):
                prime_numbers.append(num)

        return prime_numbers

    # Define the upper limit and the number of threads
    limit = int(input("Enter the upper limit: "))
    num_threads = int(input("Enter the number of threads: "))

    # Calculate the range of numbers each thread will handle
    numbers_per_thread = limit // num_threads

    prime_numbers = []
    with concurrent.futures.ThreadPoolExecutor() as executor:
        futures = []
        for i in range(num_threads):
            start = i * numbers_per_thread + 2
            end = start + numbers_per_thread - 1 if i < num_threads - 1 else limit

            futures.append(executor.submit(find_primes, start, end))

        for future in concurrent.futures.as_completed(futures):
            prime_numbers.extend(future.result())

    print("Prime numbers up to", limit, "are:")
    print(prime_numbers)



def find_factors_ofNum(in_number):
    import concurrent.futures

    def find_factors(n):
        factors = []
        for i in range(1, n + 1):
            if n % i == 0:
                factors.append(i)
        return factors

    def find_factors_parallel(start, end):
        factors_list = []
        for num in range(start, end + 1):
            factors = find_factors(num)
            factors_list.append((num, factors))
        return factors_list

    # Prompt the user to enter a number and the number of threads
    number = in_number
    num_threads = int(input("Enter the number of threads: "))

    # Calculate the range of numbers each thread will handle
    numbers_per_thread = number // num_threads

    factors = []
    with concurrent.futures.ThreadPoolExecutor() as executor:
        futures = []
        for i in range(num_threads):
            start = i * numbers_per_thread + 1
            end = start + numbers_per_thread - 1 if i < num_threads - 1 else number

            futures.append(executor.submit(find_factors_parallel, start, end))

        for future in concurrent.futures.as_completed(futures):
            factors.extend(future.result())

    print("Factors of", number, "are:")
    for num, factor_list in factors:
        print("Number:", num, "Factors:", factor_list)

find_factors_ofNum(prime100)