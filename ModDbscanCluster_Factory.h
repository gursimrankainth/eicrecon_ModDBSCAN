// Gursimran Kainth 

#pragma once

#include "algorithms/calorimetry/ModDbscanCluster_Factory.h" 
#include "extensions/jana/JOmniFactory.h"
#include "services/algorithms_init/AlgorithmsInit_service.h"

namespace eicrecon {

    class ModDbscanCluster_Factory : public JOmniFactory<ModDbscanCluster_Factory, ModDbscanClusterConfig> {

        public: 
            using AlgoDBSCAN = eicrecon::ModDbscanCluster; 
        private: 
            std::unique_ptr<AlgoDBSCAN> m_algo; 

            PodioInput<edm4eic::CalorimeterHitCollection> m_hits_input {this};  // Collection of hits
            PodioOutput<edm4eic::DBSCANClusterCollection> m_DBSCAN_output {this};  // Collection of clusters

            // Parameters Step 1: epsilon, min_neighbors, energy_threshold
            ParameterRef<int> m_eps_1 {this, "epsilon1", config().epsilon1};
            ParameterRef<int> m_minNbrs_1 {this, "minNeighbors1", config().minNeighbors1};
            ParameterRef<double> m_eThres {this, "energyThreshold", config().energyThreshold};

            Service<AlgorithmsInit_service> m_algorithmsInit {this};

        public:
            void Configure() {
                m_algo = std::make_unique<AlgoDBSCAN>(GetPrefix());
                m_algo->level(static_cast<algorithms::LogLevel>(logger()->level()));
                m_algo->applyConfig(config());
                m_algo->init();
            }

            void ChangeRun(int64_t run_number) {
                // Handle run changes if needed 
            }

            void Process(int64_t run_number, uint64_t event_number) {
                m_algo->process({m_hits_input()}, {m_DBSCAN_output().get()});
            }

    }; 
    
} 



