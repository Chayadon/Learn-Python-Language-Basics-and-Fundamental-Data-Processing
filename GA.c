#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POPULATION_SIZE 50
#define NUM_GENERATIONS 100
#define MUTATION_RATE 0.1

// A simple function that we want to maximize
double fitness_function(double x) {
    return x * x;
}

int main() {
    srand(time(NULL));

    // Initialize the population with random values
    double population[POPULATION_SIZE];
    for (int i = 0; i < POPULATION_SIZE; i++) {
        population[i] = (double)rand() / RAND_MAX;
    }

    // Evolve the population over NUM_GENERATIONS generations
    for (int g = 0; g < NUM_GENERATIONS; g++) {
        // Calculate the fitness of each individual
        double fitness[POPULATION_SIZE];
        for (int i = 0; i < POPULATION_SIZE; i++) {
            fitness[i] = fitness_function(population[i]);
        }

        // Select the fittest individuals for reproduction
        double new_population[POPULATION_SIZE];
        for (int i = 0; i < POPULATION_SIZE; i++) {
            // Select the first parent randomly
            int parent1 = rand() % POPULATION_SIZE;
            // Select the second parent randomly, with a bias towards fitter individuals
            int parent2 = rand() % POPULATION_SIZE;
            if (fitness[parent1] > fitness[parent2]) {
                new_population[i] = population[parent1];
            } else {
                new_population[i] = population[parent2];
            }

            // Mutate the individual with a small probability
            if (rand() / (double)RAND_MAX < MUTATION_RATE) {
                new_population[i] = (double)rand() / RAND_MAX;
            }
        }

        // Replace the old population with the new population
        for (int i = 0; i < POPULATION_SIZE; i++) {
            population[i] = new_population[i];
        }
    }

    // Print the fittest individual in the final population
    double fittest = 0;
    for (int i = 0; i < POPULATION_SIZE; i++) {
        if (fitness_function(population[i]) > fittest) {
            fittest = population[i];
        }
    }
    printf("Fittest individual: %f\n", fittest);

    return 0;
}
